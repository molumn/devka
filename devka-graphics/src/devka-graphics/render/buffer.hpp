//
// Created by molumn on 22. 7. 3.
//

#ifndef DEVKA_BUFFER_HPP
#define DEVKA_BUFFER_HPP

#include <string>
#include <devka-common/units/primitives.hpp>

namespace dvk::graphics {

    enum class ShaderDataType {
        None = 0,
        Bool,
        Int, Int2, Int3, Int4,
        Float, Float2, Float3, Float4,
        Float3x3, Float4x4,
    };

    static int32 ShaderDataTypeSize(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::Bool:              return 1;
            case ShaderDataType::Int:               return 4;
            case ShaderDataType::Int2:              return 4 * 2;
            case ShaderDataType::Int3:              return 4 * 3;
            case ShaderDataType::Int4:              return 4 * 4;
            case ShaderDataType::Float:             return 4;
            case ShaderDataType::Float2:            return 4 * 2;
            case ShaderDataType::Float3:            return 4 * 3;
            case ShaderDataType::Float4:            return 4 * 4;
            case ShaderDataType::Float3x3:          return 4 * 4 * 4;
            case ShaderDataType::Float4x4:          return 3 * 3 * 4;
            case ShaderDataType::None:              break;
        }
        DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "No such element[ShaderDataType, {0}] <-- file: {1}, line: {2}",
                  (int32) type);
        return 0;
    }

    struct BufferElement {
        std::string name = "No Element";
        ShaderDataType type = ShaderDataType::None;
        int32 size = 0;
        size_t offset = 0;
        b1 normalized = false;

        BufferElement() = default;

        BufferElement(ShaderDataType type, const std::string &name, b1 normalized = false)
                : type(type), size(ShaderDataTypeSize(type)), offset(0), normalized(normalized)
        {
            this->name = name;
        }

        [[nodiscard]] int32 getComponentCount() const {
            switch (type) {
                case ShaderDataType::None:              break;
                case ShaderDataType::Bool:
                case ShaderDataType::Float:
                case ShaderDataType::Int:               return 1;
                case ShaderDataType::Int2:
                case ShaderDataType::Float2:            return 2;
                case ShaderDataType::Int3:
                case ShaderDataType::Float3:            return 3;
                case ShaderDataType::Int4:
                case ShaderDataType::Float4:            return 4;
                case ShaderDataType::Float3x3:          return 16;
                case ShaderDataType::Float4x4:          return 9;
            }
            DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "No such element[ShaderDataType, {0}] <-- file: {1}, line: {2}",
                      (int32) type);
            return 0;
        }

    };

    class BufferLayout {
    public:
        BufferLayout() = default;

        BufferLayout(std::initializer_list<BufferElement> elements)
                : m_Elements(elements) {
            CalculateOffsetsAndStride();
        }

        [[nodiscard]] int32 getStride() const { return m_Stride; }

        [[nodiscard]] const std::vector<BufferElement> &getElements() const { return m_Elements; }

        std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }

        std::vector<BufferElement>::iterator end() { return m_Elements.end(); }

        [[nodiscard]] std::vector<BufferElement>::const_iterator begin() const { return m_Elements.begin(); }

        [[nodiscard]] std::vector<BufferElement>::const_iterator end() const { return m_Elements.end(); }

    private:
        void CalculateOffsetsAndStride() {
            size_t offset = 0;
            m_Stride = 0;
            for (auto &element: m_Elements) {
                element.offset = offset;
                offset += element.size;
                m_Stride += element.size;
            }
        }

    private:
        std::vector<BufferElement> m_Elements;
        int32 m_Stride = 0;
    };

#define EMPTY_BUFFER_LAYOUT     dvk::graphics::BufferLayout()


    struct VertexBufferParam {
        f32 *vertexes = nullptr;
        uint32 size = 0;
        uint32 VBO = 0;
        BufferLayout layout;

        VertexBufferParam() = default;

        VertexBufferParam(f32 *vertexes, uint32 size, uint32 VBO, const BufferLayout& layout = EMPTY_BUFFER_LAYOUT)
                : vertexes(vertexes), size(size), VBO(VBO), layout(layout) {
        }

    };


    struct IndexBufferParam {
        uint32 *indices = nullptr;
        uint32 count = 0;
        uint32 IBO = 0;

        IndexBufferParam() {}

        IndexBufferParam(uint32 *indices, uint32 count, uint32 IBO)
                : indices(indices), count(count), IBO(IBO) {
        }

    };


    class VertexBuffer {
    public:
        virtual ~VertexBuffer() = default;

        virtual void bind() const = 0;

        virtual void unbind() const = 0;

        virtual void setData(const void *data, uint32 size) = 0;

        virtual void updateData() = 0;

        [[nodiscard]] virtual const BufferLayout &getLayout() const = 0;

        virtual void setLayout(const BufferLayout &layout) = 0;

        static Ref<VertexBuffer> create(uint32 size);

        static Ref<VertexBuffer> create(float *vertices, uint32 size);

    protected:
        VertexBufferParam i_param;
    };

    // Currently Hazel only supports 32-bit index buffers
    class IndexBuffer {
    public:
        virtual ~IndexBuffer() = default;

        virtual void bind() const = 0;

        virtual void unbind() const = 0;

        [[nodiscard]] virtual uint32 getCount() const = 0;

        static Ref<IndexBuffer> create(uint32 *indices, uint32 count);

    protected:
        IndexBufferParam i_param;
    };


} // graphics

#endif //DEVKA_BUFFER_HPP

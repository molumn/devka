//
// Created by molumn on 22. 7. 3.
//

#ifndef DEVKA_OPENGL_BUFFER_HPP
#define DEVKA_OPENGL_BUFFER_HPP

#include "devka-graphics/render/buffer.hpp"

namespace dvk::graphics {

        class DK_API OpenGLVertexBuffer final : public VertexBuffer
        {
        public:
            explicit OpenGLVertexBuffer(uint32 size);
            OpenGLVertexBuffer(f32* vertexes, uint32 size);
            ~OpenGLVertexBuffer() final;

            void bind() const override;
            void unbind() const override;

            void setData(const void* data, uint32 size) override;
            void updateData() override;

            [[nodiscard]] const BufferLayout& getLayout() const override;
            void setLayout(const BufferLayout& layout) override;

        };

        // Currently Hazel only supports 32-bit index buffers
        class DK_API OpenGLIndexBuffer final : public IndexBuffer
        {
        public:
            OpenGLIndexBuffer(uint32* indices, uint32 count);
            ~OpenGLIndexBuffer() final;

            void bind() const override;
            void unbind() const override;

            [[nodiscard]] uint32 getCount() const override;

        };

    } // graphics

#endif //DEVKA_OPENGL_BUFFER_HPP

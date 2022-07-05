//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_OPENGL_VERTEX_ARRAY_HPP
#define DEVKA_OPENGL_VERTEX_ARRAY_HPP

#include "devka-graphics/render/vertex_array.hpp"

namespace dvk::graphics {

    class DK_API OpenGLVertexArray final : public VertexArray {
    public:
        OpenGLVertexArray();
        ~OpenGLVertexArray() final;

        void bind() const override;
        void unBind() const override;

        void addVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) override;
        void setIndexBuffer(const Ref<IndexBuffer>& indexBuffer) override;

        [[nodiscard]] const std::vector<Ref<VertexBuffer>>& getVertexBuffers() const override { return vertexBuffers; }
        [[nodiscard]] const Ref<IndexBuffer>& getIndexBuffer() const override { return indexBuffer; }

    private:
        uint32 VAO = 0;
        uint32 vertexBufferIndex = 0;
        std::vector<Ref<VertexBuffer>>  vertexBuffers;
        Ref<IndexBuffer>                indexBuffer;
    };

}


#endif //DEVKA_OPENGL_VERTEX_ARRAY_HPP

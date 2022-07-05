//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_VERTEX_ARRAY_HPP
#define DEVKA_VERTEX_ARRAY_HPP

#include "devka-graphics/render/buffer.hpp"

namespace dvk::graphics {

        class DK_API VertexArray {
        public:
            virtual ~VertexArray() = default;

            virtual void bind() const = 0;
            virtual void unBind() const = 0;

            virtual void addVertexBuffer(const Ref<VertexBuffer>& vertexBuffer) = 0;
            virtual void setIndexBuffer(const Ref<IndexBuffer>& indexBuffer) = 0;

            [[nodiscard]] virtual const std::vector<Ref<VertexBuffer>>& getVertexBuffers() const = 0;
            [[nodiscard]] virtual const Ref<IndexBuffer>& getIndexBuffer() const = 0;

            static Ref<VertexArray> create();

        };

    } // graphics

#endif //DEVKA_VERTEX_ARRAY_HPP

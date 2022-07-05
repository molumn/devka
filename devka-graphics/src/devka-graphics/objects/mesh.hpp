//
// Created by molumn on 22. 7. 5.
//

#ifndef DEVKA_MESH_HPP
#define DEVKA_MESH_HPP

#include <devka-common/utils/utils.hpp>
#include "devka-graphics/render/vertex_array.hpp"

namespace dvk::graphics {

    class DK_API Mesh {
    public:
        Mesh();
        ~Mesh() = default;

        void drawTriangles(uint32 indexCount = 0);
        void drawLines(uint32 vertexCount);

        void addIndependentObject(const Ref<VertexBuffer>& vertexBuffer);
        void addIndependentObject(f32* vertexes, uint32 count);

        void setIndices(const Ref<IndexBuffer>& indexBuffer);
        void setIndices(uint32* indices, uint32 count);

        static Ref<Mesh> createTriangle(f32* vertexes, uint32* indices, uint32 count);  ///todo : glm::vec3

    private:
        Ref<VertexArray>    vertexArray;
    };

} // graphics

#endif //DEVKA_MESH_HPP

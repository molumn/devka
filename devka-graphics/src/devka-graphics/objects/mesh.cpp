//
// Created by molumn on 22. 7. 5.
//
#include <devka-common/pch.hpp>

#include "devka-graphics/render/render_api.hpp"

#include "mesh.hpp"

namespace dvk::graphics {

    Mesh::Mesh() {
        vertexArray = VertexArray::create();
    }

    void Mesh::drawTriangles(uint32 indexCount) {
        RenderAPI::drawTriangles(vertexArray, indexCount);
    }

    void Mesh::drawLines(uint32 vertexCount) {
        RenderAPI::drawLines(vertexArray, vertexCount);
    }

    void Mesh::addIndependentObject(const Ref <VertexBuffer>& vertexBuffer) {
        vertexArray->addVertexBuffer(vertexBuffer);
    }

    void Mesh::addIndependentObject(f32 *vertexes, uint32 count) {
        auto vbo = VertexBuffer::create(vertexes, sizeof(f32) * count);
        vbo->setLayout(BufferLayout {
            BufferElement { ShaderDataType::Float3, "i_position" },
            BufferElement { ShaderDataType::Float4, "i_color" } //todo
        });
        vertexArray->addVertexBuffer(vbo);
    }

    void Mesh::setIndices(const Ref <IndexBuffer>& indexBuffer) {
        vertexArray->setIndexBuffer(indexBuffer);
    }

    void Mesh::setIndices(uint32 *indices, uint32 count) {
        auto indexBuffer = IndexBuffer::create(indices, count);
        vertexArray->setIndexBuffer(indexBuffer);
    }

    Ref<Mesh> Mesh::createTriangle(f32 *vertexes, uint32* indices, uint32 count) {
        auto mesh = createRef<Mesh>();
        auto vbo = VertexBuffer::create(vertexes, sizeof(f32) * count);
        vbo->setLayout(BufferLayout {
                BufferElement { ShaderDataType::Float3, "i_position",  }
        });
        auto ibo = IndexBuffer::create(indices, 3);
        mesh->vertexArray->addVertexBuffer(vbo);
        mesh->vertexArray->setIndexBuffer(ibo);
        return mesh;
    }


} // graphics
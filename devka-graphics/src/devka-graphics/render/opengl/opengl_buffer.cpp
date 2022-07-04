//
// Created by molumn on 22. 7. 3.
//
#include <devka-common/pch.hpp>

#include "opengl_buffer.hpp"

#include <glad/glad.h>

namespace dvk::graphics {

    OpenGLVertexBuffer::OpenGLVertexBuffer(uint32 size) {
        this->i_param = VertexBufferParam { nullptr, size, 0 };
        glCreateBuffers(1, &i_param.VBO);
        glBindBuffer(GL_ARRAY_BUFFER, i_param.VBO);
        glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(f32 *vertexes, uint32 size) {
        this->i_param = VertexBufferParam { vertexes, size, 0 };
        glCreateBuffers(1, &i_param.VBO);
        glBindBuffer(GL_ARRAY_BUFFER, i_param.VBO);
        glBufferData(GL_ARRAY_BUFFER, size, vertexes, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer() {
        glDeleteBuffers(1, &i_param.VBO);
    }

    void OpenGLVertexBuffer::bind() const {
        glBindBuffer(GL_ARRAY_BUFFER, i_param.VBO);
    }

    void OpenGLVertexBuffer::unbind() const {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void OpenGLVertexBuffer::setData(const void *data, uint32 size) {
        glBindBuffer(GL_ARRAY_BUFFER, i_param.VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
    }

    void OpenGLVertexBuffer::updateData() {
        glBindBuffer(GL_ARRAY_BUFFER, i_param.VBO);
        glBufferSubData(GL_ARRAY_BUFFER, 0, i_param.size, i_param.vertexes);
    }

    const BufferLayout &OpenGLVertexBuffer::getLayout() const {
        return i_param.layout;
    }

    void OpenGLVertexBuffer::setLayout(const BufferLayout &layout) {
        i_param.layout = layout;
    }




    OpenGLIndexBuffer::OpenGLIndexBuffer(uint32 *indices, uint32 count) {
        this->i_param = IndexBufferParam { indices, count, 0 };
        glCreateBuffers(1, &i_param.IBO);
        glBindBuffer(GL_ARRAY_BUFFER, i_param.IBO);
        glBufferData(GL_ARRAY_BUFFER, count, indices, GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer() {
        glDeleteBuffers(1, &i_param.IBO);
    }

    void OpenGLIndexBuffer::bind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, i_param.IBO);
    }

    void OpenGLIndexBuffer::unbind() const {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    uint32 OpenGLIndexBuffer::getCount() const {
        return i_param.count;
    }


} // graphics
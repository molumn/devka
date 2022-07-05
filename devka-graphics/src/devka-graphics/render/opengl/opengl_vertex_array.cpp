//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include <glad/glad.h>

#include "opengl_vertex_array.hpp"

namespace dvk::graphics {

    GLenum OpenGLTypeCast(ShaderDataType type) {
        switch (type) {
            case ShaderDataType::None:              break;
            case ShaderDataType::Bool:              return GL_BOOL;
            case ShaderDataType::Int:
            case ShaderDataType::Int2:
            case ShaderDataType::Int3:
            case ShaderDataType::Int4:              return GL_INT;
            case ShaderDataType::Float:
            case ShaderDataType::Float2:
            case ShaderDataType::Float3:
            case ShaderDataType::Float4:
            case ShaderDataType::Float3x3:
            case ShaderDataType::Float4x4:          return GL_FLOAT;
        }
        DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "Unknown or Unsupported Type : {0} -- [file: {1}, line: {2}]", (uint32)type);
        return GL_FALSE;
    }

    OpenGLVertexArray::OpenGLVertexArray() {
        glGenVertexArrays(1, &VAO);
    }

    OpenGLVertexArray::~OpenGLVertexArray() {
        glDeleteVertexArrays(1, &VAO);
    }

    void OpenGLVertexArray::bind() const {
        glBindVertexArray(VAO);
    }

    void OpenGLVertexArray::unBind() const {
        glBindVertexArray(0);
    }

    void OpenGLVertexArray::addVertexBuffer(const Ref<VertexBuffer> &vertexBuffer) {
        glBindVertexArray(VAO);
        vertexBuffer->bind();

        const auto& layout = vertexBuffer->getLayout();
        for (const auto& element : layout) {
            switch (element.type) {
                case ShaderDataType::Bool:
                case ShaderDataType::Int:
                case ShaderDataType::Int2:
                case ShaderDataType::Int3:
                case ShaderDataType::Int4:
                {
                    glEnableVertexAttribArray(vertexBufferIndex);
                    glVertexAttribIPointer(
                            vertexBufferIndex,
                            element.getComponentCount(),
                            OpenGLTypeCast(element.type),
                            layout.getStride(),
                            (const void*)element.offset
                            );
                    vertexBufferIndex++;
                    break;
                }
                case ShaderDataType::Float:
                case ShaderDataType::Float2:
                case ShaderDataType::Float3:
                case ShaderDataType::Float4:
                {
                    glEnableVertexAttribArray(vertexBufferIndex);
                    glVertexAttribPointer(
                            vertexBufferIndex,
                            element.getComponentCount(),
                            OpenGLTypeCast(element.type),
                            element.normalized ? GL_TRUE : GL_FALSE,
                            layout.getStride(),
                            (const void*)element.offset
                            );
                    vertexBufferIndex++;
                    break;
                }
                case ShaderDataType::Float3x3:
                case ShaderDataType::Float4x4:
                {
                    uint8 count = element.getComponentCount();
                    for (uint8 i = 0; i < count; i++) {
                        glEnableVertexAttribArray(vertexBufferIndex);
                        glVertexAttribPointer(
                                vertexBufferIndex,
                                count,
                                ShaderDataTypeSize(element.type),
                                element.normalized ? GL_TRUE : GL_FALSE,
                                layout.getStride(),
                                (const void*)(element.offset + sizeof(f32) * count * i)
                                );
                        glVertexAttribDivisor(vertexBufferIndex, 1);
                        vertexBufferIndex++;
                    }
                    break;
                }
                default:
                    DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "Unknown or Unsupported Data Type -- [file: {0}, line {1}]");
            }
        }

        vertexBuffers.push_back(vertexBuffer);

    }

    void OpenGLVertexArray::setIndexBuffer(const Ref<IndexBuffer> &indexBuffer) {
        glBindVertexArray(VAO);
        indexBuffer->bind();

        this->indexBuffer = indexBuffer;
    }


}


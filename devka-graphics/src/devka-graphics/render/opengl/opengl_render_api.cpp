//
// Created by molumn on 22. 7. 5.
//
#include <devka-common/pch.hpp>

#include <glad/glad.h>

#include "opengl_render_api.hpp"

namespace dvk::graphics {

    OpenGLRenderAPI::OpenGLRenderAPI() {
#ifdef DK_DEBUG
//        glEnable();
//        glEnable();
//        glDebugMessageCallback(Open)
#endif
//        glEnable(GL_BLEND);
//        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//        glEnable(GL_DEPTH_TEST);
//        glEnable(GL_LINE_SMOOTH);
    }

    void OpenGLRenderAPI::i_setViewport(uint32 x, uint32 y, uint32 width, uint32 height) {
        glViewport(x, y, width, height);
    }

    void OpenGLRenderAPI::i_clearColor(f32 r, f32 g, f32 b, f32 a) {
        glClearColor(r, g, b, a);
    }

    void OpenGLRenderAPI::i_clear() {
        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
    }

    void OpenGLRenderAPI::i_drawTriangles(Ref<VertexArray> &vertexArray, uint32 indexCount) {
        vertexArray->bind();
        uint32 count = indexCount ? indexCount : vertexArray->getIndexBuffer()->getCount();
        glDrawElements(GL_TRIANGLES, (int32)count, GL_UNSIGNED_INT, nullptr);
    }

    void OpenGLRenderAPI::i_drawLines(Ref<VertexArray> &vertexArray, uint32 vertexCount) {
        vertexArray->bind();
        glDrawArrays(GL_LINES, 0, (int32)vertexCount);
    }

    void OpenGLRenderAPI::i_setLineWidth(f32 width) {
        glLineWidth(width);
    }

} // graphics
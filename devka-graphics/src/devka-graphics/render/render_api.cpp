//
// Created by molumn on 22. 7. 5.
//
#include <devka-common/pch.hpp>

#include "devka-graphics/graphic/graphic_api_check.hpp"
#include "opengl/opengl_render_api.hpp"

#include "render_api.hpp"

namespace dvk::graphics {

    Ref<RenderAPI> RenderAPI::instance = nullptr;

    void RenderAPI::init() {
        switch (GraphicAPI::get()) {
            case GraphicAPIType::None:          break;
            case GraphicAPIType::OpenGL:        instance = createRef<OpenGLRenderAPI>();
        }
    }

    void RenderAPI::setViewport(uint32 x, uint32 y, uint32 width, uint32 height) {
        instance->i_setViewport(x, y, width, height);
    }

    void RenderAPI::clearColor(f32 r, f32 g, f32 b, f32 a) {
        instance->i_clearColor(r, g, b, a);
    }

    void RenderAPI::clear() {
        instance->i_clear();
    }

    void RenderAPI::drawTriangles(Ref<VertexArray> &vertexArray, uint32 indexCount) {
        instance->i_drawTriangles(vertexArray, indexCount);
    }

    void RenderAPI::drawLines(Ref<VertexArray> &vertexArray, uint32 vertexCount) {
        instance->i_drawLines(vertexArray, vertexCount);
    }

    void RenderAPI::setLineWidth(f32 width) {
        instance->i_setLineWidth(width);
    }


} // graphics

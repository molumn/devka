//
// Created by molumn on 22. 7. 5.
//

#ifndef DEVKA_OPENGL_RENDER_API_HPP
#define DEVKA_OPENGL_RENDER_API_HPP

#include "devka-graphics/render/render_api.hpp"

namespace dvk::graphics {

    class DK_API OpenGLRenderAPI : public RenderAPI {
    public:
        OpenGLRenderAPI();
        ~OpenGLRenderAPI() = default;

        void i_setViewport(uint32 x, uint32 y, uint32 width, uint32 height) override;
        void i_clearColor(f32 r, f32 g, f32 b, f32 a) override;
        void i_clear() override;

        void i_drawTriangles(Ref<VertexArray>& vertexArray, uint32 indexCount) override;
        void i_drawLines(Ref<VertexArray>& vertexArray, uint32 vertexCount) override;
        void i_setLineWidth(f32 width) override;
        
    };

} // graphics

#endif //DEVKA_OPENGL_RENDER_API_HPP

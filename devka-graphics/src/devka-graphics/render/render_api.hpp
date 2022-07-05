//
// Created by molumn on 22. 7. 5.
//

#ifndef DEVKA_RENDER_API_HPP
#define DEVKA_RENDER_API_HPP

#include <devka-common/utils/utils.hpp>
#include <devka-common/units/primitives.hpp>

#include "devka-graphics/render/vertex_array.hpp"

namespace dvk::graphics {

    class DK_API RenderAPI {
    public:
        
        static void init();
        
        static void setViewport(uint32 x, uint32 y, uint32 width, uint32 height);
        static void clearColor(f32 r, f32 g, f32 b, f32 a);
        static void clear();
        
        static void drawTriangles(Ref<VertexArray>& vertexArray, uint32 indexCount = 0);
        static void drawLines(Ref<VertexArray>& vertexArray, uint32 vertexCount);
        static void setLineWidth(f32 width);
        
    protected:

        virtual void i_setViewport(uint32 x, uint32 y, uint32 width, uint32 height) = 0;
        virtual void i_clearColor(f32 r, f32 g, f32 b, f32 a) = 0;
        virtual void i_clear() = 0;

        virtual void i_drawTriangles(Ref<VertexArray>& vertexArray, uint32 indexCount) = 0;
        virtual void i_drawLines(Ref<VertexArray>& vertexArray, uint32 vertexCount) = 0;
        virtual void i_setLineWidth(f32 width) = 0;
        
        
    private:
        static Ref<RenderAPI>      instance;
    };

} // graphics

#endif //DEVKA_RENDER_API_HPP

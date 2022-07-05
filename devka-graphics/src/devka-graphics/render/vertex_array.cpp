//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "devka-graphics/graphic/graphic_api_check.hpp"
#include "devka-graphics/render/opengl/opengl_vertex_array.hpp"

#include "vertex_array.hpp"

namespace dvk::graphics {

    Ref<VertexArray> VertexArray::create() {
        switch (GraphicAPI::get()) {
            case GraphicAPIType::None:          break;
            case GraphicAPIType::OpenGL:        return createRef<OpenGLVertexArray>();
        }
        DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "Unknown or Unsupported GraphicAPI[{0}]!", (uint32)GraphicAPI::get());
        return nullptr;
    }


} // graphics
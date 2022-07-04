//
// Created by molumn on 22. 7. 3.
//
#include <devka-common/pch.hpp>

#include "devka-graphics/graphic/graphic_api_check.hpp"

#include "opengl/opengl_buffer.hpp"

#include "buffer.hpp"

namespace dvk::graphics {

    Ref<VertexBuffer> VertexBuffer::create(uint32 size) {
        switch (GraphicAPI::get()) {
            case GraphicAPIType::None:          break;
            case GraphicAPIType::OpenGL:        return createRef<OpenGLVertexBuffer>(size);
        }
        DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "Unknown or Unsupported GraphicAPI[{0}]!", (int32)GraphicAPI::get())
        return nullptr;
    }

    Ref<VertexBuffer> VertexBuffer::create(f32 *vertexes, uint32 size) {
        switch (GraphicAPI::get()) {
            case GraphicAPIType::None:          break;
            case GraphicAPIType::OpenGL:        return createRef<OpenGLVertexBuffer>(vertexes, size);
        }
        DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "Unknown or Unsupported GraphicAPI[{0}]!", (int32)GraphicAPI::get())
        return nullptr;
    }

    Ref<IndexBuffer> IndexBuffer::create(uint32 *indices, uint32 count) {
        switch (GraphicAPI::get()) {
            case GraphicAPIType::None:          break;
            case GraphicAPIType::OpenGL:        return createRef<OpenGLIndexBuffer>(indices, count);
        }
        DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "Unknown or Unsupported GraphicAPI[{0}]!", (int32)GraphicAPI::get())
        return nullptr;
    }


} // graphics
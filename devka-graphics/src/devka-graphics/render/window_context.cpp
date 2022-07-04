//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "devka-graphics/graphic/graphic_api_check.hpp"

#include "opengl/opengl_window_context.hpp"

#include "window_context.hpp"

namespace dvk::graphics {

    Ref<WindowContext> WindowContext::createContext(const WindowContextInfo& info) {
        switch (GraphicAPI::get()) {
            case GraphicAPIType::None:          break;
            case GraphicAPIType::OpenGL:        return createRef<OpenGLWindowContext>(info);
        }
        DK_ASSERT(false, DK_GRAPHIC_LOG_CODE, "GraphicAPI type is set as {0}. [filename: {1}, line: {2}]", (int32)GraphicAPI::get())
        return nullptr;
    }

    WindowContext::WindowContext(const WindowContextInfo& info) {
        m_info = info;
    }

    b1 WindowContext::isRunning() const {
        return m_info.is_running;
    }

    void WindowContext::setRunning(b1 is_running) {
        m_info.is_running = is_running;
    }


} // graphics
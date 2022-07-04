//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "devka-graphics/graphic/opengl.hpp"

#include "opengl_window_context.hpp"

namespace dvk::graphics {

    void OpenGLWindowContext::init() {
        OpenGLManager::initGraphics();

        GLFWwindow* graphic_context = glfwCreateWindow(m_info.width, m_info.height, m_info.name.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(graphic_context, &m_info);

        glfwSetWindowCloseCallback(graphic_context, [](GLFWwindow* window) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);
            info->is_running = false;
        });

        glfwMakeContextCurrent(graphic_context);

        m_graphic_handle = graphic_context;
    }

    void OpenGLWindowContext::run() {
        glfwSwapBuffers(GLFW_WINDOW_HANDLE(m_graphic_handle));
    }

    void OpenGLWindowContext::destroy() {
        OpenGLManager::terminateGraphics(); //todo
    }

    b1 OpenGLWindowContext::onEvent(Event &event) {
        return false;
    }

    void OpenGLWindowContext::resetInfo(const WindowContextInfo& info) {
        m_info = info;
    }

    void OpenGLWindowContext::updateEventCallbackFn(const EventCallbackStdFn &event_callback) {
        m_info.eventCallback = event_callback;
    }

    void *OpenGLWindowContext::getContextHandle() {
        return m_graphic_handle;
    }


}

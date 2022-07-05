//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "devka-graphics/events/window_context_event.hpp"
#include "devka-graphics/events/mouse_event.hpp"
#include "devka-graphics/events/key_event.hpp"
#include "devka-graphics/graphic/opengl.hpp"

#include "opengl_window_context.hpp"

namespace dvk::graphics {

    static void GLFWErrorCallback(int32 error, const char* description) {
        DK_LOG_ERROR(DK_GRAPHIC_LOG_CODE, "GLFW error [{0}] : {1}", error, description);
    }

    void OpenGLWindowContext::init() {
        OpenGLManager::initGraphics();

        GLFWwindow* graphic_context = glfwCreateWindow(m_info.width, m_info.height, m_info.name.c_str(), nullptr, nullptr);
        glfwSetWindowUserPointer(graphic_context, &m_info);

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); //test
        glfwSetErrorCallback(GLFWErrorCallback);

        OpenGLManager::applyGlad(graphic_context);


        glfwSetWindowCloseCallback(graphic_context, [](GLFWwindow* window) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);
            info->is_running = false;                                                   // todo

            WindowContextCloseEvent event(window);
            info->eventCallback(event);
        });

        glfwSetWindowPosCallback(graphic_context, [](GLFWwindow* window, int32 x, int32 y) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);
//            info.x = x;
//            info.y = y;

            WindowContextMoveEvent event(window, x, y);
            info->eventCallback(event);
        });

        glfwSetWindowFocusCallback(graphic_context, [](GLFWwindow* window, int32 focus) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);
//            info.focus = focus;

            WindowContextFocusEvent event(window, focus);
            info->eventCallback(event);
        });

        glfwSetWindowSizeCallback(graphic_context, [](GLFWwindow* window, int32 width, int32 height) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);
            info->width = width;
            info->height = height;

            WindowContextResizeEvent event(window, width, height);
            info->eventCallback(event);
        });

        glfwSetKeyCallback(graphic_context, [](GLFWwindow* window, int32 keycode, int32 scan, int32 action, int32 mods) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    KeyPressEvent event(keycode, mods);
                    info->eventCallback(event);
                } break;
                case GLFW_REPEAT: {
                    KeyPressEvent event(keycode, mods, true);
                    info->eventCallback(event);
                } break;
                case GLFW_RELEASE: {
                    KeyReleaseEvent event(keycode, mods);
                    info->eventCallback(event);
                } break;
                default: break;
            }
        });

        glfwSetMouseButtonCallback(graphic_context, [](GLFWwindow* window, int32 mouse_code, int32 action, int32 mods) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);

            switch (action) {
                case GLFW_PRESS: {
                    MouseClickEvent event(mouse_code, mods);
                    info->eventCallback(event);
                } break;
                case GLFW_RELEASE: {
                    MouseReleaseEvent event(mouse_code, mods);
                    info->eventCallback(event);
                } break;
                default: break;
            }
        });

        glfwSetCharModsCallback(graphic_context, [](GLFWwindow* window, uint32 codepoint, int32 mods) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);

            CharModsEvent event(codepoint, mods);
            info->eventCallback(event);
        });

        glfwSetScrollCallback(graphic_context, [](GLFWwindow* window, f64 x_offset, f64 y_offset) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);

            ScrollEvent event(x_offset, y_offset);
            info->eventCallback(event);
        });

        glfwSetCursorPosCallback(graphic_context, [](GLFWwindow* window, f64 x, f64 y) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);

            MouseMoveEvent event(x, y);
            info->eventCallback(event);
        });

        glfwSetCursorEnterCallback(graphic_context, [](GLFWwindow* window, int32 entered) {
            auto* info = (WindowContextInfo*)glfwGetWindowUserPointer(window);

            CursorEnterEvent event(entered);
            info->eventCallback(event);
        });

        m_graphic_handle = graphic_context;
    }

    void OpenGLWindowContext::run() {
        glfwSwapBuffers(GLFW_WINDOW_HANDLE(m_graphic_handle));
    }

    void OpenGLWindowContext::destroy() {
//        OpenGLManager::terminateGraphics(); //todo
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

    void *OpenGLWindowContext::getContextHandle() const {
        return m_graphic_handle;
    }

    void OpenGLWindowContext::focusContextHandle() {
        glfwMakeContextCurrent(GLFW_WINDOW_HANDLE(m_graphic_handle));
    }

    OpenGLWindowContext::~OpenGLWindowContext() {
        OpenGLManager::terminateGraphics(); //todo
    }


}

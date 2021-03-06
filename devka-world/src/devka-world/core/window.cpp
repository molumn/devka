//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include <devka-graphics/graphic/graphic_export.hpp>

#include "window.hpp"

namespace dvk {

    Window::Window(const std::string &name, int32 width, int32 height, b1 vsync) {
        context = graphics::WindowContext::createContext(graphics::WindowContextInfo(name, width, height, vsync));
    }

    void Window::init() {
        context->init();
        mesh = createRef<graphics::Mesh>();

        f32 vertexes[21] = {
                -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                0.5f,  -0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
                0.0f,   0.5f, 0.0f, 1.0f, 0.0f, 1.0f, 1.0f
        };

        uint32 indices[3] = { 0, 1, 2 };

        mesh->addIndependentObject(
                vertexes,
                21
                );
        mesh->setIndices(indices, 3);
    }

    void Window::run() {
        mesh->drawTriangles();
        context->run();
        graphics::GraphicExports::pollEvents();
    }

    void Window::destroy() {
        context->destroy();
    }

    void Window::setEventCallback(const EventCallbackStdFn &event_callback) {
        context->updateEventCallbackFn(event_callback);
    }

    b1 Window::isRunning() const {
        return context->isRunning();
    }

    void Window::setRunning(b1 is_running) {
        context->setRunning(is_running);
    }


} // dvk
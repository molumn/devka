//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_OPENGL_WINDOW_CONTEXT_HPP
#define DEVKA_OPENGL_WINDOW_CONTEXT_HPP

#include "devka-graphics/render/window_context.hpp"

namespace dvk::graphics {

    class DK_API OpenGLWindowContext final : public WindowContext {
    public:
        OpenGLWindowContext() : WindowContext() {}
        explicit OpenGLWindowContext(const WindowContextInfo& info) : WindowContext(info) {}
        ~OpenGLWindowContext() final = default;

        void init() override;
        void run() override;
        void destroy() override;
        b1 onEvent(Event& event) override;

        void resetInfo(const WindowContextInfo& info) override;
        void updateEventCallbackFn(const EventCallbackStdFn& event_callback) override;

        void* getContextHandle() override;

    private:
        void* m_graphic_handle = nullptr;
    };

}

#endif //DEVKA_OPENGL_WINDOW_CONTEXT_HPP

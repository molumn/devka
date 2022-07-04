//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_WINDOW_CONTEXT_EVENT_HPP
#define DEVKA_WINDOW_CONTEXT_EVENT_HPP

#include <devka-common/units/primitives.hpp>
#include <devka-common/event/event.hpp>

namespace dvk::graphics {

    class WindowContextEvent : public Event {
    public:
        virtual ~WindowContextEvent() = default;

        EVENT_CATEGORY_SET(EventCategory::DisplayWindow)

        [[nodiscard]] void* getContext() const { return window_context; }
        [[nodiscard]] std::string toString() const override;

    protected:
        explicit WindowContextEvent(void* window_context) : window_context(window_context) {}

        void* window_context;
    };


    class WindowContextLoadEvent final : public WindowContextEvent {
    public:
        WindowContextLoadEvent() : WindowContextEvent(nullptr) {}
        explicit WindowContextLoadEvent(void* window_context) : WindowContextEvent(window_context) {}
        ~WindowContextLoadEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowLoad, "window_context_load")

        [[nodiscard]] std::string toString() const override;
    };

    class WindowContextStartEvent final : public WindowContextEvent {
    public:
        WindowContextStartEvent() : WindowContextEvent(nullptr) {}
        explicit WindowContextStartEvent(void* window_context) : WindowContextEvent(window_context) {}
        ~WindowContextStartEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowStart, "window_context_start")

        [[nodiscard]] std::string toString() const override;
    };

    class WindowContextPreRunEvent final : public WindowContextEvent {
    public:
        WindowContextPreRunEvent() : WindowContextEvent(nullptr) {}
        explicit WindowContextPreRunEvent(void* window_context) : WindowContextEvent(window_context) {}
        ~WindowContextPreRunEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowPreRun, "window_context_pre_run")

        [[nodiscard]] std::string toString() const override;
    };

    class WindowContextPostRunEvent final : public WindowContextEvent {
    public:
        WindowContextPostRunEvent() : WindowContextEvent(nullptr) {}
        explicit WindowContextPostRunEvent(void* window_context) : WindowContextEvent(window_context) {}
        ~WindowContextPostRunEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowPostRun, "window_context_post_run")

        [[nodiscard]] std::string toString() const override;
    };

    class WindowContextCloseEvent final : public WindowContextEvent {
    public:
        WindowContextCloseEvent() : WindowContextEvent(nullptr) {}
        explicit WindowContextCloseEvent(void* window_context) : WindowContextEvent(window_context) {}
        ~WindowContextCloseEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowClose, "window_context_close")

        [[nodiscard]] std::string toString() const override;
    };

    class WindowContextMoveEvent final : public WindowContextEvent {
    public:
        WindowContextMoveEvent() : WindowContextEvent(nullptr), x(0), y(0) {}
        explicit WindowContextMoveEvent(void* window_context, int32 x, int32 y) : WindowContextEvent(window_context), x(x), y(y) {}
        ~WindowContextMoveEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowMove, "window_context_move")

        [[nodiscard]] std::string toString() const override;

    private:
        int32 x, y;
    };

    class WindowContextFocusEvent final : public WindowContextEvent {
    public:
        WindowContextFocusEvent() : WindowContextEvent(nullptr), focus(false) {}
        explicit WindowContextFocusEvent(void* window_context, int32 focus) : WindowContextEvent(window_context), focus(focus) {}
        ~WindowContextFocusEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowFocus, "window_context_focus")

        [[nodiscard]] int32 getFocus() const { return focus; }

        [[nodiscard]] std::string toString() const override;

    private:
        int32 focus;
    };

    class WindowContextResizeEvent final : public WindowContextEvent {
    public:
        WindowContextResizeEvent() : WindowContextEvent(nullptr), width(0), height(0) {}
        explicit WindowContextResizeEvent(void* window_context, int32 width, int32 height) : WindowContextEvent(window_context), width(width), height(height) {}
        ~WindowContextResizeEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::DisplayWindowResize, "window_context_resize")

        [[nodiscard]] std::string toString() const override;

    private:
        int32 width, height;
    };



}

#endif //DEVKA_WINDOW_CONTEXT_EVENT_HPP

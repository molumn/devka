//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_MOUSE_EVENT_HPP
#define DEVKA_MOUSE_EVENT_HPP

#include <devka-common/event/event.hpp>

namespace dvk::graphics {

    class MouseEvent : public Event {
    public:
        virtual ~MouseEvent() = default;

        EVENT_CATEGORY_SET(EventCategory::MouseMods)

        [[nodiscard]] int32 getMouseCode() const { return mouse_code; }
        [[nodiscard]] int32 getModifiers() const { return mods; }

        [[nodiscard]] std::string toString() const override;

    protected:
        explicit MouseEvent(int32 mouse_code, int32 mods = 0x00) : mouse_code(mouse_code) {}

        int32 mouse_code;
        int32 mods{};
    };

    class MouseClickEvent final : public MouseEvent {
    public:
        explicit MouseClickEvent(int32 mouse_code, int32 mods = 0x00) : MouseEvent(mouse_code, mods) {}
        ~MouseClickEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::MouseClick, "mouse_click")

        [[nodiscard]] std::string toString() const override;

    };

    class MouseReleaseEvent final : public MouseEvent {
    public:
        explicit MouseReleaseEvent(int32 mouse_code, int32 mods = 0x00) : MouseEvent(mouse_code, mods) {}
        ~MouseReleaseEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::MouseRelease, "mouse_release")

        [[nodiscard]] std::string toString() const override;

    };

    class ScrollEvent : public Event {
    public:
        explicit ScrollEvent(f64 x_offset, f64 y_offset) : x_offset(x_offset), y_offset(y_offset) {}
        ~ScrollEvent() = default;

        EVENT_CATEGORY_SET(EventCategory::Scroll)
        INHERIT_DK_EVENT_BASIC_METHOD(EventType::Scroll, "scroll")

        [[nodiscard]] f64 getXOffset() const { return x_offset; }
        [[nodiscard]] f64 getYOffset() const { return y_offset; }

        [[nodiscard]] std::string toString() const override;

    protected:
        f64 x_offset, y_offset;
    
    };

    class MouseMoveEvent : public Event {
    public:
        explicit MouseMoveEvent(f64 x, f64 y) : x(x), y(y) {}
        virtual ~MouseMoveEvent() = default;

        EVENT_CATEGORY_SET(EventCategory::Position)
        INHERIT_DK_EVENT_BASIC_METHOD(EventType::MouseMove, "mouse_move")

        [[nodiscard]] f64 getXOffset() const { return x; }
        [[nodiscard]] f64 getYOffset() const { return y; }

        [[nodiscard]] std::string toString() const override;

    protected:
        f64 x, y;

    };

    class CursorEnterEvent : public Event {
    public:
        explicit CursorEnterEvent(int32 entered) : entered(entered) {}
        virtual ~CursorEnterEvent() = default;

        EVENT_CATEGORY_SET(EventCategory::Position)
        INHERIT_DK_EVENT_BASIC_METHOD(EventType::CursorEnter, "cursor_enter")

        [[nodiscard]] int32 getEnterCode() const { return entered; }

        [[nodiscard]] std::string toString() const override;

    protected:
        int32 entered;

    };
    
    
    
    
    

}


#endif //DEVKA_MOUSE_EVENT_HPP

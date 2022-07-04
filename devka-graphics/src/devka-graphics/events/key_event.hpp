//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_KEY_EVENT_HPP
#define DEVKA_KEY_EVENT_HPP

#include <devka-common/event/event.hpp>
#include <devka-common/units/primitives.hpp>

namespace dvk::graphics {

    class KeyEvent : public Event {
    public:
        virtual ~KeyEvent() = default;

        EVENT_CATEGORY_SET(EventCategory::KeyMods)

        [[nodiscard]] int32 getKeyCode() const { return keycode; }
        [[nodiscard]] int32 getModifiers() const { return mods; }

        [[nodiscard]] std::string toString() const override;

    protected:
        explicit KeyEvent(int32 keycode, int32 mods = 0x00) : keycode(keycode), mods(mods) {}

        int32 keycode;
        int32 mods;
    };

    class KeyPressEvent final : public KeyEvent {
    public:
        explicit KeyPressEvent(int32 keycode, int32 mods = 0x00, b1 repeat = false) : KeyEvent(keycode, mods), repeat(repeat) {}
        ~KeyPressEvent() final = default;

        [[nodiscard]] b1 isRepeat() const { return repeat; }

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::KeyPress, "key_press")

        [[nodiscard]] std::string toString() const override;

    private:
        b1 repeat;
    };

    class KeyReleaseEvent final : public KeyEvent {
    public:
        explicit KeyReleaseEvent(int32 keycode, int32 mods = 0x00) : KeyEvent(keycode, mods) {}
        ~KeyReleaseEvent() final = default;

        INHERIT_DK_EVENT_BASIC_METHOD(EventType::KeyRelease, "key_release")

        [[nodiscard]] std::string toString() const override;

    };

    class CharModsEvent : public Event {
    public:
        CharModsEvent(uint32 character, int32 mods) : character(character), mods(mods) {}
        virtual ~CharModsEvent() = default;

        EVENT_CATEGORY_SET(EventCategory::CharMods)
        INHERIT_DK_EVENT_BASIC_METHOD(EventType::CharMods, "char")

        [[nodiscard]] uint32 getCharacter() const { return character; }
        [[nodiscard]] int32 getModifiers() const { return mods; }

        std::string toString() const override;

    protected:
        uint32 character;
        int32 mods;
    };


}


#endif //DEVKA_KEY_EVENT_HPP

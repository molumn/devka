//
// Created by molumn on 22. 7. 2.
//

#ifndef DEVKA_EVENT_HPP
#define DEVKA_EVENT_HPP

#include <string>

namespace dvk {

    enum class EventCategory : int {
        Event = 0x0,
        Application = 0x1,
        DisplayWindow = 0x10, DisplayContent = 0x20,
        KeyMods = 0x0100, MouseMods = 0x0200, Scroll = 0x0400, CharMods = 0x0800, Position = 0x0F00,


        Plugin = 0x10000000,
    };

    enum class EventType : int {
        Event = 0x0,
        ApplicationLoad = 0x0001, ApplicationStart = 0x0002, ApplicationPreRun = 0x0004, ApplicationPostRun = 0x0008, ApplicationClose = 0x000F,
            DisplayWindowLoad = 0x0010, DisplayWindowStart = 0x0020, DisplayWindowPreRun = 0x0040, DisplayWindowPostRun = 0x0080, DisplayWindowClose = 0x00F0,
            DisplayWindowMove = 0x1000, DisplayWindowFocus = 0x2000, DisplayWindowResize = 0x4000,
                DisplayContentCreate = 0x0100, DisplayContentInit = 0x0200, DisplayContentPreUpdate = 0x0400, DisplayContentPostUpdate = 0x0800, DisplayContentDestroy = 0x0F00,

        KeyPress = 0x010000, KeyRelease = 0x020000, MouseClick = 0x04000000, MouseRelease = 0x080000, Scroll = 0x0F0000, MouseMove = 0x100000,
            CharMods = 0x200000, CursorEnter = 0x400000,

        PluginLoad = 0x10000000, PluginEnable = 0x20000000, PluginDisable = 0x40000000,
    };


    /**
     *  @b Try @b macro : @b @code INHERIT_DK_EVENT_BASIC_METHOD(event_category, event_type)
     */
    /* abstract */ class Event {
    public:
        virtual ~Event() = default;

        [[nodiscard]] virtual std::string getName() const = 0;

        [[nodiscard]] virtual std::string toString() const = 0;
    private:
    };



/**
 *  Inheritance Example :
 * @code class ExampleEvent : dvk::Event {
 * public:
 *     ExampleEvent();
 *     virtual ~ExampleEvent();
 *
 *     INHERIT_DK_EVENT_BASIC_METHOD(dvk::EventCategory::Event, dvk::EventType::Event)
 *
 *     virtual const std::string& toString() const override {
 *         return "ExampleEvent[ category: \"Event\", type: \"Event\" ]";
 *     }
 *
 */

#define EVENT_CATEGORY_SET(event_category) \
static EventCategory getCategory() { return event_category; }     \


#define INHERIT_DK_EVENT_BASIC_METHOD(event_type, identifier_name) \
virtual std::string getName() const override { return identifier_name; }      \
static EventType getType() { return event_type; }


} // dvk


#endif //DEVKA_EVENT_HPP

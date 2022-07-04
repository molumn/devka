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
        KeyMods = 0x0100, MouseMods = 0x0200, Scroll = 0x0400, CharMods = 0x0800,


        Plugin = 0x10000000,
    };

    enum class EventType : int {
        Event = 0x0,
        ApplicationLoad = 0x0001, ApplicationStart = 0x0002, ApplicationPreRun = 0x0004, ApplicationPostRun = 0x0008, ApplicationClose = 0x000F,
            DisplayWindowLoad = 0x0010, DisplayWindowStart = 0x0020, DisplayWindowPreRun = 0x0040, DisplayWindowPostRun = 0x0080, DisplayWindowClose = 0x00F0,
                DisplayContentCreate = 0x0100, DisplayContentInit = 0x0200, DisplayContentPreUpdate = 0x0400, DisplayContentPostUpdate = 0x0800, DisplayContentDestroy = 0x0F00,

        KeyPress = 0x010000, KeyRepeat = 0x020000, MousePress = 0x04000000, MouseRepeat = 0x080000, Scroll = 0x0F0000,
            CharMods = 0x100000,

        PluginLoad = 0x10000000, PluginEnable = 0x20000000, PluginDisable = 0x40000000,
    };


    /**
     *  @b Try @b macro : @b @code INHERIT_DK_EVENT_BASIC_METHOD(event_category, event_type)
     */
    /* abstract */ class Event {
    public:
        virtual ~Event() = default;

        [[nodiscard]] virtual EventCategory getCategory() const = 0;
        [[nodiscard]] virtual EventType getType() const = 0;

        [[nodiscard]] virtual const std::string& toString() const = 0;
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
#define INHERIT_DK_EVENT_BASIC_METHOD(event_category, event_type) \
virtual EventCategory getCategory() const override { return event_category; }\
virtual EventType getType() const override { return event_type; } \
static EventCategory getCategory() { return event_category; }     \
static EventType getType() { return event_type; }


} // dvk


#endif //DEVKA_EVENT_HPP

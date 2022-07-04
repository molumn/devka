//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_WINDOW_CONTEXT_HPP
#define DEVKA_WINDOW_CONTEXT_HPP

#include <devka-common/event/event.hpp>

namespace dvk {

//    b1 (*EventCallbackFn)(Event& event);    //todo
    typedef std::function<b1(Event &)> EventCallbackStdFn;     //todo

    namespace graphics {

        struct WindowContextInfo {
            std::string name;
            int32 width;
            int32 height;
            b1 is_running;
            b1 vsync;

            EventCallbackStdFn eventCallback;

            explicit WindowContextInfo(const std::string &name = "No Name", int32 width = 1080, int32 height = 960,
                                       b1 vsync = false)
                    : width(width), height(height), eventCallback([](Event &event) { return false; }), is_running(true),
                      vsync(vsync) {
                this->name = name;
            }

            WindowContextInfo(const std::string &name, int32 width, int32 height, b1 vsync,
                              const EventCallbackStdFn &event_callback)
                    : width(width), height(height), eventCallback(event_callback), is_running(true), vsync(vsync) {
                this->name = name;
            }

        };

        class DK_API WindowContext {
        public:
            WindowContext() = default;

            explicit WindowContext(const WindowContextInfo &info);

            virtual ~WindowContext() = default;

            virtual void init() = 0;

            virtual void run() = 0;

            virtual void destroy() = 0;

            virtual b1 onEvent(Event &event) = 0;

            virtual void resetInfo(const WindowContextInfo &info) = 0;

            virtual void updateEventCallbackFn(const EventCallbackStdFn &event_callback) = 0;

            b1 isRunning() const;

            void setRunning(b1 is_running);

            virtual void *getContextHandle() = 0;

            static Ref<WindowContext> createContext(const WindowContextInfo &info = WindowContextInfo());

        protected:
            WindowContextInfo m_info;
        };

    } // graphics
} // devka

#endif //DEVKA_WINDOW_CONTEXT_HPP

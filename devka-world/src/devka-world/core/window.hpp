//
// Created by molumn on 22. 7. 4.
//

#ifndef DEVKA_WINDOW_HPP
#define DEVKA_WINDOW_HPP

#include <devka-graphics/render/window_context.hpp>

namespace dvk {

    class DK_API Window {
    public:
        explicit Window(const std::string& name = "No Name", int32 width = 1800, int32 height = 960, b1 vsync = false);
        ~Window() = default;

        void init();
        void run();
        void destroy();
        void setEventCallback(const EventCallbackStdFn& event_callback);

        [[nodiscard]] b1 isRunning() const;
        void setRunning(b1 running);

    private:
        Ref<graphics::WindowContext>    context;
    };

} // dvk

#endif //DEVKA_WINDOW_HPP

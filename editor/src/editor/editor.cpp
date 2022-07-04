//
// Created by molumn on 22. 7. 2.
//
#include <devka-world/world.hpp>


int main() {

    DK_CREATE_LOGGER("Graphics", DK_GRAPHIC_LOG_CODE, dvk::LogLevel::TRACE);
    DK_CREATE_LOGGER("Engine", DK_ENGINE_LOG_CODE, dvk::LogLevel::TRACE);
    dvk::graphics::GraphicAPI::set(dvk::graphics::GraphicAPIType::OpenGL);

    dvk::Window window = dvk::Window();

    window.setEventCallback([](dvk::Event& event) {
        DK_LOG_TRACE(DK_ENGINE_LOG_CODE, "{0}", event.toString());
        return true;
    });

    window.init();

    while(window.isRunning()) {
        window.run();
    }

    window.destroy();

}


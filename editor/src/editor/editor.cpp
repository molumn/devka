//
// Created by molumn on 22. 7. 2.
//
#include <devka-world/world.hpp>


int main() {

    DK_CREATE_LOGGER("Graphics", DK_GRAPHIC_LOG_CODE, dvk::LogLevel::TRACE);
    dvk::graphics::GraphicAPI::set(dvk::graphics::GraphicAPIType::OpenGL);

    dvk::Window window = dvk::Window();

    window.init();

    while(window.isRunning()) {
        window.run();
    }

    window.destroy();

}


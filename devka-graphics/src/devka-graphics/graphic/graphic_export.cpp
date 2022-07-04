//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "graphic_api_check.hpp"
#include "opengl.hpp"

#include "graphic_export.hpp"

namespace dvk::graphics {

    void GraphicExports::pollEvents() {
        switch (GraphicAPI::get()) {
            case GraphicAPIType::None:      break;
            case GraphicAPIType::OpenGL:    glfwPollEvents();
        }
    }


}

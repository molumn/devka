//
// Created by molumn on 22. 7. 3.
//
#include <devka-common/pch.hpp>

#include "graphic_api_check.hpp"

namespace dvk::graphics {

    GraphicAPIType GraphicAPI::api = GraphicAPIType::None;

    GraphicAPIType GraphicAPI::get() {
        return api;
    }

    void GraphicAPI::set(GraphicAPIType value) {
        api = value;
    }


}

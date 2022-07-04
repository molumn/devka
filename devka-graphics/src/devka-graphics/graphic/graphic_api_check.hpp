//
// Created by molumn on 22. 7. 3.
//

#ifndef DEVKA_GRAPHIC_API_CHECK_HPP
#define DEVKA_GRAPHIC_API_CHECK_HPP

namespace dvk::graphics {

    enum class GraphicAPIType {
        None = 0,
        OpenGL
    };

    class DK_API GraphicAPI {
    public:
        static GraphicAPIType get();
        static void set(GraphicAPIType value);
    private:
        static GraphicAPIType api;
    };

}

#endif //DEVKA_GRAPHIC_API_CHECK_HPP

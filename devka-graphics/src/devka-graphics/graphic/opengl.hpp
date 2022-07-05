//
// Created by molumn on 22. 7. 3.
//

#ifndef DEVKA_OPENGL_HPP
#define DEVKA_OPENGL_HPP

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace dvk::graphics {

    class DK_API OpenGLManager {
    public:
        static void initGraphics();
        static void terminateGraphics();

        static void applyGlad(GLFWwindow* window);

        static b1 isInited();

    private:
        static b1 is_inited;
    };

#define GLFW_WINDOW_HANDLE(x)       (GLFWwindow*)(x)

}

#endif //DEVKA_OPENGL_HPP

//
// Created by molumn on 22. 7. 4.
//
#include <devka-common/pch.hpp>

#include "opengl.hpp"

namespace dvk::graphics {

    b1 OpenGLManager::is_inited = false;

    void OpenGLManager::initGraphics() {
        if(is_inited) {
            DK_LOG_WARN(DK_GRAPHIC_LOG_CODE, "OpenGL had already initialized!");
//            DK_DEBUG_BREAK()  // should?
        }
        is_inited = true;

        b1 result = glfwInit();

    }

    void OpenGLManager::terminateGraphics() {
        if(is_inited) {
            glfwTerminate();
            is_inited = false;
        } else {
            DK_LOG_WARN(DK_GRAPHIC_LOG_CODE, "Program had tried to terminate non-initialized OpenGL");
//        DK_DEBUG_BREAK()  // should?
        }
    }

    void OpenGLManager::applyGlad(GLFWwindow* window) {

        glfwMakeContextCurrent(window);
        int32 result = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        DK_ASSERT(result, DK_GRAPHIC_LOG_CODE, "Failed to load glad (result : {0})", result);

        DK_LOG_INFO(DK_GRAPHIC_LOG_CODE, "glad Info :");
        DK_LOG_INFO(DK_GRAPHIC_LOG_CODE, "   Vendor : {0}", glGetString(GL_VENDOR));
        DK_LOG_INFO(DK_GRAPHIC_LOG_CODE, "   Renderer : {0}", glGetString(GL_RENDERER));
        DK_LOG_INFO(DK_GRAPHIC_LOG_CODE, "   Version : {0}", glGetString(GL_VERSION));

    }

    b1 OpenGLManager::isInited() {
        return is_inited;
    }


}

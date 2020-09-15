#include <IonEngine/IonEngine.h>

#include <IonEngine/extern/OpenGL.h>

#include <iostream>

namespace IonEngine {

    void entryPoint()
    {
        if(GLFW_TRUE != glfwInit()) {
            std::cerr << "glfwInit failed\n";
            return;
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

        GLFWwindow* window = glfwCreateWindow(640, 480, "IonEngine", nullptr, nullptr);
        glfwMakeContextCurrent(window);


        while(!glfwWindowShouldClose(window)) {
            glfwPollEvents();
            glfwSwapBuffers(window);
        }

        glfwDestroyWindow(window);
        glfwTerminate();
    }

}
#include <IonEngine.h>

#include <IonEngine/extern/OpenGL.h>

namespace IonEngine::Input {

    IonEngine::Window* IonEngine::Input::InputState::m_window = nullptr;

    bool InputState::isKeyPressed(Key key) noexcept
    {
        if(!m_window) {
            ION_CORE_LOG_WARN("Input possing without window, returning false");
            return false;
        }

        int state = glfwGetKey((GLFWwindow*)(m_window->getNativeHandler()), (int)key);
        if(GLFW_PRESS == state) {
            return true;
        }

        return false;
    }

    bool InputState::isMouseButtonPressed(MouseButton button) noexcept
    {
        if(!m_window) {
            ION_CORE_LOG_WARN("Input possing without window, returning false");
            return false;
        }

        int state = glfwGetMouseButton((GLFWwindow*)(m_window->getNativeHandler()), (int)button);
        if(GLFW_PRESS == state) {
            return true;
        }

        return false;
    }

    MousePosition InputState::getMousePosition() noexcept
    {
        if(!m_window) {
            ION_CORE_LOG_WARN("Input possing without window, returning 0/0");
            return { 0, 0 };
        }

        double xpos = 0, ypos = 0;
        glfwGetCursorPos((GLFWwindow*)(m_window->getNativeHandler()), &xpos, &ypos);
        return { xpos, ypos };
    }

}

#include <IonEngine.h>

#include <glfw/glfw3.h>

namespace IonEngine::Platform {

    bool GLInput::isKeyPressedImpl(Key key) noexcept
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

    bool GLInput::isMouseButtonPressedImpl(MouseButton button) noexcept
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

    MousePosition GLInput::getMousePositionImpl() noexcept
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

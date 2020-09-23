#include <IonEngine.h>

#include <IonEngine/extern/OpenGL.h>

#include <memory>

class CrossPlatformWindow: public IonEngine::Window
{
public:
    CrossPlatformWindow(const WindowProps& props):
        Window{ props }
    {
        if(!glfwInit()) {
            ION_CORE_LOG_ERROR("glfwInit failed");
            ION_CORE_ASSERT(false, "Couldn't create window");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        m_handle = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
        ION_CORE_ASSERT(nullptr != m_handle, "Couldn't create window");

        glfwMakeContextCurrent(m_handle);
        if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            ION_CORE_ASSERT(false, "Couldn't load glad");
        }

        setCallbacks();
    }

    virtual ~CrossPlatformWindow() noexcept override
    {
        glfwDestroyWindow(m_handle);
        glfwTerminate();
    }

    virtual bool setVSync(bool value) noexcept override
    {
        bool prev = m_props.VSync;
        if(value) {
            glfwSwapInterval(1);
        } else {
            glfwSwapInterval(0);
        }
        m_props.VSync = value;
        return prev;
    }

    virtual void onUpdate() override
    {
        glfwPollEvents();
        glfwSwapBuffers(m_handle);
    }

    virtual void* getNativeHandler() const noexcept override
    {
        return m_handle;
    }

private:
    void setCallbacks() noexcept
    {
        glfwSetWindowUserPointer(m_handle, this);

        glfwSetKeyCallback(m_handle, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            auto keyCode = static_cast<IonEngine::Input::Key>(key);

            switch(action) {
            case GLFW_PRESS:
            {
                IonEngine::Events::KeyPressedEvent e(keyCode);
                eventCallback(e);
                break;
            }
            case GLFW_REPEAT:
            {
                IonEngine::Events::KeyRepeatedEvent e(keyCode, 1);
                eventCallback(e);
                break;
            }
            case GLFW_RELEASE:
            {
                IonEngine::Events::KeyReleasedEvent e(keyCode);
                eventCallback(e);
                break;
            }
            }
        });

        glfwSetCharCallback(m_handle, [](GLFWwindow* window, unsigned int character) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::CharInputEvent e(character);
            eventCallback(e);
        });

        glfwSetCursorPosCallback(m_handle, [](GLFWwindow* window, double xpos, double ypos) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::MouseMovedEvent e(xpos, ypos);
            eventCallback(e);
        });

        glfwSetMouseButtonCallback(m_handle, [](GLFWwindow* window, int button, int action, int mods) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            auto buttonCode = static_cast<IonEngine::Input::MouseButton>(button);

            switch(action) {
            case GLFW_PRESS:
            {
                IonEngine::Events::MouseButtonPressedEvent e(buttonCode);
                eventCallback(e);
                break;
            }
            case GLFW_RELEASE:
            {
                IonEngine::Events::MouseButtonReleasedEvent e(buttonCode);
                eventCallback(e);
                break;
            }
            }
        });

        glfwSetScrollCallback(m_handle, [](GLFWwindow* window, double xoffset, double yoffset) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::MouseScrolledEvent e(yoffset, xoffset);
            eventCallback(e);
        });

        glfwSetWindowCloseCallback(m_handle, [](GLFWwindow* window) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::WindowClosedEvent e;
            eventCallback(e);
        });

        glfwSetWindowSizeCallback(m_handle, [](GLFWwindow* window, int width, int height) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::WindowResizedEvent e(width, height);
            eventCallback(e);
        });

        glfwSetFramebufferSizeCallback(m_handle, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        glfwSetWindowPosCallback(m_handle, [](GLFWwindow* window, int xpos, int ypos) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::WindowMovedEvent e(xpos, ypos);
            eventCallback(e);
        });

        glfwSetWindowFocusCallback(m_handle, [](GLFWwindow* window, int focus) {
            auto eventCallback = ((CrossPlatformWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            if(focus) {
                IonEngine::Events::WindowFocusedEvent e;
                eventCallback(e);
            } else {
                IonEngine::Events::WindowLostFocusEvent e;
                eventCallback(e);
            }
        });
    }

private:

    GLFWwindow* m_handle = nullptr;
};

std::unique_ptr<IonEngine::Window> IonEngine::Window::createWindow(const WindowProps& props)
{
    return std::make_unique<CrossPlatformWindow>(props);
}

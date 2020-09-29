#include <IonEngine.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <memory>

namespace IonEngine::Platform {

    GLWindow::GLWindow(const WindowProps& props):
        Window{ props }
    {
        if(!glfwInit()) {
            ION_CORE_LOG_ERROR("glfwInit failed");
            ION_CORE_ASSERT(false, "Couldn't create window");
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GL_TRUE);
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

        m_handle = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
        ION_CORE_ASSERT(nullptr != m_handle, "Couldn't create window");

        setCallbacks();

        m_context = IonEngine::Graphics::Context::create(*this);
    }

    GLWindow::~GLWindow() noexcept 
    {
        glfwDestroyWindow(m_handle);
        glfwTerminate();
    }

    bool GLWindow::setVSync(bool value) noexcept 
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

    void GLWindow::onUpdate()
    {
        glfwPollEvents();
    }

    void GLWindow::onRender()
    {
        m_context->swapBuffers();
    }

    void* GLWindow::getNativeHandler() const noexcept
    {
        return m_handle;
    }

    void GLWindow::setCallbacks() noexcept
    {
        glfwSetWindowUserPointer(m_handle, this);

        glfwSetKeyCallback(m_handle, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

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
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::CharInputEvent e(character);
            eventCallback(e);
        });

        glfwSetCursorPosCallback(m_handle, [](GLFWwindow* window, double xpos, double ypos) {
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::MouseMovedEvent e(xpos, ypos);
            eventCallback(e);
        });

        glfwSetMouseButtonCallback(m_handle, [](GLFWwindow* window, int button, int action, int mods) {
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

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
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::MouseScrolledEvent e(yoffset, xoffset);
            eventCallback(e);
        });

        glfwSetWindowCloseCallback(m_handle, [](GLFWwindow* window) {
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::WindowClosedEvent e;
            eventCallback(e);
        });

        glfwSetWindowSizeCallback(m_handle, [](GLFWwindow* window, int width, int height) {
            auto cpWindow = (GLWindow*)glfwGetWindowUserPointer(window);
            cpWindow->m_props.width = width;
            cpWindow->m_props.height = height;

            auto eventCallback = cpWindow->m_eventCallback;

            IonEngine::Events::WindowResizedEvent e(width, height);
            eventCallback(e);
        });

        glfwSetFramebufferSizeCallback(m_handle, [](GLFWwindow* window, int width, int height) {
            glViewport(0, 0, width, height);
        });

        glfwSetWindowPosCallback(m_handle, [](GLFWwindow* window, int xpos, int ypos) {
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            IonEngine::Events::WindowMovedEvent e(xpos, ypos);
            eventCallback(e);
        });

        glfwSetWindowFocusCallback(m_handle, [](GLFWwindow* window, int focus) {
            auto eventCallback = ((GLWindow*)glfwGetWindowUserPointer(window))->m_eventCallback;

            if(focus) {
                IonEngine::Events::WindowFocusedEvent e;
                eventCallback(e);
            } else {
                IonEngine::Events::WindowLostFocusEvent e;
                eventCallback(e);
            }
        });
    }

}

#include <IonEngine.h>

namespace IonEngine {

    Window::Window(const WindowProps& props):
        m_props{ props },
        m_context{ nullptr }
    {
        ION_CORE_LOG_INFO("Creating window \"{}\" {}x{}", props.title, props.width, props.height);
    }

    const Window::WindowProps& Window::getProps() const noexcept
    {
        return m_props;
    }

    bool Window::setVSync(bool value) noexcept
    {
        return false;
    }

    Window::EventCallback Window::setEventCallback(const EventCallback& callback) noexcept
    {
        auto prev = m_eventCallback;
        m_eventCallback = callback;
        return prev;
    }

    void Window::onUpdate()
    {

    }

    void Window::onRender()
    {

    }

    void* Window::getNativeHandler() const noexcept
    {
        return nullptr;
    }

    std::unique_ptr<Window> Window::create(const WindowProps& props)
    {
        switch(IonEngine::Platform::API::getGraphicsAPI()) {
        case IonEngine::Platform::API::GraphicsAPI::OpenGL:
        {
            auto window = std::make_unique<IonEngine::Platform::GLWindow>(props);
            IonEngine::InputState::m_window = window.get();
            IonEngine::InputState::m_instance = std::make_unique<IonEngine::Platform::GLInput>();
            return std::move(window);
            break;
        }
        default:
        {
            ION_CORE_ASSERT(false, "API is not supported");
        }
        }
    }
}

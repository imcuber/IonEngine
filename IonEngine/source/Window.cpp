#include <IonEngine.h>

namespace IonEngine {

    Window::Window(const WindowProps& props):
        m_props{ props }
    {
        IonEngine::Input::InputState::m_window = this;
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
    {}

    void* Window::getNativeHandler() const noexcept
    {
        return nullptr;
    }
}

#include <IonEngine.h>

#include <IonEngine/Events/EventsVirtualDefinitions.inl>

namespace IonEngine::Events {

    IONENGINE_EVENTS_DEFINITIONS(Window, EventCategory::Window)

    IONENGINE_EVENTS_DEFINITIONS(WindowClosed, EventCategory::Window)

    IONENGINE_EVENTS_DEFINITIONS(WindowFocused, EventCategory::Window)

    IONENGINE_EVENTS_DEFINITIONS(WindowLostFocus, EventCategory::Window)

    WindowResizedEvent::WindowResizedEvent(std::size_t width, std::size_t height) noexcept:
        WindowEvent{}, 
        width{ width },
        height{ height }
    {}

    std::string WindowResizedEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} size: {}x{}", WindowEvent::toString(), width, height);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(WindowResized, EventCategory::Window)

    WindowMovedEvent::WindowMovedEvent(float x, float y) noexcept:
        WindowEvent{},
        x{ x },
        y{ y }
    {}

    std::string WindowMovedEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} position x:{} y:{}", WindowEvent::toString(), x, y);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(WindowMoved, EventCategory::Window)

}

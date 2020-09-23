#include <IonEngine.h>

#include <IonEngine/Events/EventsVirtualDefinitions.inl>

namespace IonEngine::Events {

    IONENGINE_EVENTS_DEFINITIONS(Mouse, EventCategory::Input | EventCategory::Mouse)

    MouseButtonPressedEvent::MouseButtonPressedEvent(IonEngine::Input::MouseButton button) noexcept:
        MouseEvent{},
        button{ button }
    {}

    std::string MouseButtonPressedEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} button = {}", MouseEvent::toString(), button);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(MouseButtonPressed, EventCategory::Input | EventCategory::Mouse)

    MouseButtonReleasedEvent::MouseButtonReleasedEvent(IonEngine::Input::MouseButton button) noexcept:
        MouseEvent{},
        button{ button }
    {}

    std::string MouseButtonReleasedEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} button = {}", MouseEvent::toString(), button);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(MouseButtonReleased, EventCategory::Input | EventCategory::Mouse)

    MouseScrolledEvent::MouseScrolledEvent(float vOffset, float hOffset) noexcept:
        MouseEvent{},
        vOffset{ vOffset },
        hOffset{ hOffset }
    {}

    std::string MouseScrolledEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} offsets v: {} h: {}", MouseEvent::toString(), vOffset, hOffset);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(MouseScrolled, EventCategory::Input | EventCategory::Mouse)

    MouseMovedEvent::MouseMovedEvent(float x, float y) noexcept:
        MouseEvent{},
        x{ x },
        y{ y }
    {}

    std::string MouseMovedEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} position x: {} y: {}", MouseEvent::toString(), x, y);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(MouseMoved, EventCategory::Input, EventCategory::Mouse)

}

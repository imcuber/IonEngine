#include <IonEngine.h>

#include <IonEngine/Events/EventsVirtualDefinitions.inl>

namespace IonEngine::Events {

    KeyboardEvent::KeyboardEvent(IonEngine::Input::Key key) noexcept:
        key{ key }
    {}

    std::string KeyboardEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} key = {}", InputEvent::toString(), key);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(Keyboard, EventCategory::Input | EventCategory::Keyboard)

    KeyPressedEvent::KeyPressedEvent(IonEngine::Input::Key key) noexcept:
        KeyboardEvent{ key }
    {}

    IONENGINE_EVENTS_DEFINITIONS(KeyPressed, EventCategory::Input | EventCategory::Keyboard)

    KeyRepeatedEvent::KeyRepeatedEvent(IonEngine::Input::Key key, int repeatCount) noexcept:
        KeyboardEvent{ key },
        repeatCount{ repeatCount }
    {}

    IONENGINE_EVENTS_DEFINITIONS(KeyRepeated, EventCategory::Input | EventCategory::Keyboard)

    KeyReleasedEvent::KeyReleasedEvent(IonEngine::Input::Key key) noexcept:
        KeyboardEvent{ key }
    {}

    IONENGINE_EVENTS_DEFINITIONS(KeyReleased, EventCategory::Input | EventCategory::Keyboard)

}

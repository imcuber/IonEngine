#include <IonEngine.h>

#include <IonEngine/Events/EventsVirtualDefinitions.inl>

namespace IonEngine::Events {

    IONENGINE_EVENTS_DEFINITIONS(Input, EventCategory::Input)

    CharInputEvent::CharInputEvent(std::uint32_t character) noexcept:
        InputEvent{},
        character{ character }
    {}

    std::string CharInputEvent::toString() const noexcept
    {
        std::string result = fmt::format("{} charcode {}: '{:c}'", InputEvent::toString(), character, character);
        return result;
    }

    IONENGINE_EVENTS_DEFINITIONS(CharInput, EventCategory::Input)
}

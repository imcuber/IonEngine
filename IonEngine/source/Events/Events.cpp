#include <IonEngine.h>

namespace IonEngine::Events {

    EventType Event::getStaticType() noexcept
    {
        return EventType::Unknown;
    }

    EventType Event::getType() const noexcept
    {
        return Event::getStaticType();
    }

    const char* Event::getEventTypeString() const noexcept
    {
        return "Unknown";
    }

    EventCategory Event::getCategory() const noexcept
    {
        return EventCategory::Unknown;
    }

    bool Event::isInCategory(EventCategory category) const noexcept
    {
        return static_cast<bool>(getCategory() & category);
    }

    std::string Event::toString() const
    {
        std::string result = fmt::format("Event[{}]", getEventTypeString());
        return result;
    }

}

std::ostream& operator<<(std::ostream& os, const IonEngine::Events::Event& e)
{
    return os << e.toString();
}

#ifndef IONENGINE_EVENTS_H
#define IONENGINE_EVENTS_H

#include <IonEngine/Core.h>

#include <functional>
#include <string>

namespace IonEngine::Events {

    enum class EventCategory
    {
        Unknown = 0,
        Application = ION_BIT(1),
        Window = ION_BIT(2),
        Input = ION_BIT(3),
        Keyboard = ION_BIT(4),
        Mouse = ION_BIT(5)
    };
    ENABLE_BITMASK_OPERATORS(EventCategory)

    enum class EventType
    {
        Unknown = 0,
        Application, AppStarted, AppStopped, AppTick, AppUpdated, AppRendered,
        Window, WindowClosed, WindowFocused, WindowLostFocus, WindowResized, WindowMoved,
        Input, CharInput,
        Keyboard, KeyPressed, KeyRepeated, KeyReleased,
        Mouse, MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved
    };

    class Event
    {
    public:
        bool handled = false;

    public:
        virtual ~Event() noexcept = default;

        static EventType getStaticType() noexcept;
        virtual EventType getType() const noexcept;
        virtual const char* getEventTypeString() const noexcept;
        virtual EventCategory getCategory() const noexcept;
        bool isInCategory(EventCategory category) const noexcept;
        
        virtual std::string toString() const;

    protected:
        Event() = default;
    };

#define IONENGINE_EVENTS_DECLARATIONS                                   \
    static EventType getStaticType() noexcept;                          \
    virtual EventType getType() const noexcept override;                \
    virtual const char* getEventTypeString() const noexcept override;   \
    virtual EventCategory getCategory() const noexcept override;

    class EventDispatcher
    {
    public:
        EventDispatcher(Event& e) noexcept:
            m_event{ e }
        {}

        ~EventDispatcher() noexcept = default;

        template <typename EventType>
        using EventFunction = std::function<bool(EventType&)>;

        template <typename EventType>
        bool dispatch(const EventFunction<EventType>& eventFunction)
        {
            if(EventType::getStaticType() == m_event.getType()) {
                eventFunction((EventType&)m_event);
                return true;
            }
            return false;
        }

    private:
        Event& m_event;
    };

}

std::ostream& operator<<(std::ostream& os, const IonEngine::Events::Event& e);

namespace IonEngine {

    using EventCategory = IonEngine::Events::EventCategory;
    using EventType = IonEngine::Events::EventType;
    using Event = IonEngine::Events::Event;
    using EventDispatcher = IonEngine::Events::EventDispatcher;

}

#include <IonEngine/Events/ApplicationEvents.h>
#include <IonEngine/Events/InputEvents.h>
#include <IonEngine/Events/WindowEvents.h>

#endif // IONENGINE_EVENTS_H

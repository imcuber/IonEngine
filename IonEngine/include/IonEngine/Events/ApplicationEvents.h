#ifndef IONENGINE_EVENTS_APPLICATIONEVENTS_H
#define IONENGINE_EVENTS_APPLICATIONEVENTS_H

#include <IonEngine/Events.h>

namespace IonEngine::Events {

    class ApplicationEvent: public Event
    {
    public:
        virtual ~ApplicationEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS

    protected:
        ApplicationEvent() = default;
    };

    class AppStartedEvent: public ApplicationEvent
    {
    public:
        AppStartedEvent() noexcept = default;
        virtual ~AppStartedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class AppStoppedEvent: public ApplicationEvent
    {
    public:
        AppStoppedEvent() noexcept = default;
        virtual ~AppStoppedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class AppTickEvent: public ApplicationEvent
    {
    public:
        AppTickEvent() noexcept = default;
        virtual ~AppTickEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class AppUpdatedEvent: public ApplicationEvent
    {
    public:
        AppUpdatedEvent() noexcept = default;
        virtual ~AppUpdatedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class AppRenderedEvent: public ApplicationEvent
    {
    public:
        AppRenderedEvent() noexcept = default;
        virtual ~AppRenderedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };
}

namespace IonEngine {

    using ApplicationEvent = IonEngine::Events::ApplicationEvent;
    using AppStartedEvent = IonEngine::Events::AppStartedEvent;
    using AppStoppedEvent = IonEngine::Events::AppStoppedEvent;
    using AppTickEventEvent = IonEngine::Events::AppTickEvent;
    using AppUpdatedEvent = IonEngine::Events::AppUpdatedEvent;
    using AppRenderedEvent = IonEngine::Events::AppRenderedEvent;

}

#endif // IONENGINE_EVENTS_APPLICATIONEVENTS_H

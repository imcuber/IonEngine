#include <IonEngine.h>

#include <IonEngine/Events/EventsVirtualDefinitions.inl>

namespace IonEngine::Events {

    IONENGINE_EVENTS_DEFINITIONS(Application, EventCategory::Application)

    IONENGINE_EVENTS_DEFINITIONS(AppStarted, EventCategory::Application)

    IONENGINE_EVENTS_DEFINITIONS(AppStopped, EventCategory::Application)

    IONENGINE_EVENTS_DEFINITIONS(AppTick, EventCategory::Application)

    IONENGINE_EVENTS_DEFINITIONS(AppUpdated, EventCategory::Application)

    IONENGINE_EVENTS_DEFINITIONS(AppRendered, EventCategory::Application)

}

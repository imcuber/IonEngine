#ifndef IONENGINE_EVENTS_INPUTEVENTS_H
#define IONENGINE_EVENTS_INPUTEVENTS_H

#include <IonEngine/Events.h>
#include <IonEngine/Input.h>

namespace IonEngine::Events {

    class InputEvent: public Event
    {
    public:
        virtual ~InputEvent() noexcept override = default;
    
        IONENGINE_EVENTS_DECLARATIONS

    protected:
        InputEvent() noexcept = default;
    };

    class CharInputEvent: public InputEvent
    {
    public:
        std::uint32_t character;

    public:
        CharInputEvent(std::uint32_t character) noexcept;
        virtual ~CharInputEvent() noexcept override = default;

        virtual std::string toString() const noexcept override;

        IONENGINE_EVENTS_DECLARATIONS
    };

}

namespace IonEngine {

    using InputEvent = IonEngine::Events::InputEvent;
    using CharInputEvent = IonEngine::Events::CharInputEvent;

}

#include <IonEngine/Events/InputEvents/KeyboardEvents.h>
#include <IonEngine/Events/InputEvents/MouseEvents.h>

#endif // IONENGINE_EVENTS_INPUTEVENTS_H

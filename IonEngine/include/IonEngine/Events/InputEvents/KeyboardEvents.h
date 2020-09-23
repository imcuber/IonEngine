#ifndef IONENGINE_EVENTS_INPUTEVENTS_KEYBOARDEVENTS_H
#define IONENGINE_EVENTS_INPUTEVENTS_KEYBOARDEVENTS_H

#include <IonEngine/Events.h>

namespace IonEngine::Events {

    class KeyboardEvent: public InputEvent
    {
    public:
        IonEngine::Input::Key key = IonEngine::Input::Key::Unknown;

    public:
        virtual ~KeyboardEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS

        virtual std::string toString() const noexcept override;

    protected:
        KeyboardEvent(IonEngine::Input::Key key) noexcept;
    };

    class KeyPressedEvent: public KeyboardEvent
    {
    public:
        KeyPressedEvent(IonEngine::Input::Key key) noexcept;
        virtual ~KeyPressedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class KeyRepeatedEvent: public KeyboardEvent
    {
    public:
        int repeatCount = 0;

    public:
        KeyRepeatedEvent(IonEngine::Input::Key key, int repeatCount) noexcept;
        virtual ~KeyRepeatedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class KeyReleasedEvent: public KeyboardEvent
    {
    public:
        KeyReleasedEvent(IonEngine::Input::Key key) noexcept;
        virtual ~KeyReleasedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };
}

#endif // IONENGINE_EVENTS_INPUTEVENTS_KEYBOARDEVENTS_H

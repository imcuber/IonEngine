#ifndef IONENGINE_EVENTS_INPUTEVENTS_MOUSEEVENTS_H
#define IONENGINE_EVENTS_INPUTEVENTS_MOUSEEVENTS_H

#include <IonEngine/Events.h>
#include <IonEngine/Input.h>

namespace IonEngine::Events {

    class MouseEvent: public InputEvent
    {
    public:
        virtual ~MouseEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS

    protected:
        MouseEvent() noexcept = default;
    };

    class MouseButtonPressedEvent: public MouseEvent
    {
    public:
        IonEngine::Input::MouseButton button = IonEngine::Input::MouseButton::Unknown;

    public:
        MouseButtonPressedEvent(IonEngine::Input::MouseButton button) noexcept;
        virtual ~MouseButtonPressedEvent() noexcept override = default;

        virtual std::string toString() const noexcept override;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class MouseButtonReleasedEvent: public MouseEvent
    {
    public:
        IonEngine::Input::MouseButton button = IonEngine::Input::MouseButton::Unknown;

    public:
        MouseButtonReleasedEvent(IonEngine::Input::MouseButton button) noexcept;
        virtual ~MouseButtonReleasedEvent() noexcept override = default;

        virtual std::string toString() const noexcept override;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class MouseScrolledEvent: public MouseEvent
    {
    public:
        float vOffset = 0.0f;
        float hOffset = 0.0f;

    public:
        MouseScrolledEvent(float vOffset, float hOffset) noexcept;
        virtual ~MouseScrolledEvent() noexcept override = default;

        virtual std::string toString() const noexcept override;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class MouseMovedEvent: public MouseEvent
    {
    public:
        float x = 0.0f;
        float y = 0.0f;

    public:
        MouseMovedEvent(float x, float y) noexcept;
        virtual ~MouseMovedEvent() noexcept override = default;

        virtual std::string toString() const noexcept override;

        IONENGINE_EVENTS_DECLARATIONS
    };
}

#endif // IONENGINE_EVENTS_INPUTEVENTS_MOUSEEVENTS_H

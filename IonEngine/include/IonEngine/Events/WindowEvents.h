#ifndef IONENGINE_EVENTS_WINDOWEVENTS_H
#define IONENGINE_EVENTS_WINDOWEVENTS_H

#include <IonEngine/Events.h>

namespace IonEngine::Events {

    class WindowEvent: public Event
    {
    public:
        virtual ~WindowEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS

    protected:
        WindowEvent() = default;
    };

    class WindowClosedEvent: public WindowEvent
    {
    public:
        WindowClosedEvent() noexcept = default;
        virtual ~WindowClosedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class WindowFocusedEvent: public WindowEvent
    {
    public:
        WindowFocusedEvent() noexcept = default;
        virtual ~WindowFocusedEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class WindowLostFocusEvent: public WindowEvent
    {
    public:
        WindowLostFocusEvent() noexcept = default;
        virtual ~WindowLostFocusEvent() noexcept override = default;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class WindowResizedEvent: public WindowEvent
    {
    public:
        std::size_t width;
        std::size_t height;

    public:
        WindowResizedEvent(std::size_t width, std::size_t height) noexcept;
        virtual ~WindowResizedEvent() noexcept override = default;

        virtual std::string toString() const noexcept override;

        IONENGINE_EVENTS_DECLARATIONS
    };

    class WindowMovedEvent: public WindowEvent
    {
    public:
        float x;
        float y;

    public:
        WindowMovedEvent(float x, float y) noexcept;
        virtual ~WindowMovedEvent() noexcept override = default;

        virtual std::string toString() const noexcept override;

        IONENGINE_EVENTS_DECLARATIONS
    };
}

namespace IonEngine {

    using WindowEvent = IonEngine::Events::WindowEvent;
    using WindowClosedEvent = IonEngine::Events::WindowClosedEvent;
    using WindowFocusedEvent = IonEngine::Events::WindowFocusedEvent;
    using WindowLostFocusEvent = IonEngine::Events::WindowLostFocusEvent;
    using WindowResizedEvent = IonEngine::Events::WindowResizedEvent;
    using WindowMovedEvent = IonEngine::Events::WindowMovedEvent;

}

#endif // IONENGINE_EVENTS_WINDOWEVENTS_H

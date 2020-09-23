#ifndef IONENGINE_WINDOW_H
#define IONENGINE_WINDOW_H

#include <IonEngine/Events.h>

#include <functional>
#include <string>

class IonEngine::Input::InputState;

namespace IonEngine {

    class Window
    {
    public:
        struct WindowProps
        {
        public:
            std::size_t width = 640;
            std::size_t height = 480;

            std::string title = "IonEngine window";

            bool VSync = true;
        };

        using EventCallback = std::function<bool(IonEngine::Events::Event&)>;
        
    public:
        static std::unique_ptr<Window> createWindow(const WindowProps& props = WindowProps{});

        virtual ~Window() noexcept = default;

        const WindowProps& getProps() const noexcept;
        virtual bool setVSync(bool value) noexcept;
       
        EventCallback setEventCallback(const EventCallback& callback) noexcept;

        virtual void onUpdate();

        virtual void* getNativeHandler() const noexcept;

    protected:
        Window(const WindowProps& props);

    protected:
        WindowProps m_props = WindowProps{};
        EventCallback m_eventCallback = [](IonEngine::Events::Event&) { return false; };
    };

}

#endif //IONENGINE_WINDOW_H

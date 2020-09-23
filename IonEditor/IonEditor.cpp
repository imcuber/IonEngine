#include <IonEngine.h>

class IonEditor: public IonEngine::Application
{
public:
    IonEditor()
    {
        m_window = IonEngine::Window::createWindow();
        m_window->setEventCallback([this](IonEngine::Events::Event& event) {
            return this->onEvent(event);
        });
    }

    virtual ~IonEditor() noexcept override = default;
    virtual void run(int argc, char* argv[]) override
    {
        while(running) {
            m_window->onUpdate();
        }
    }

    bool onEvent(IonEngine::Events::Event& e)
    {
        //ION_LOG_INFO("{}", e);
        if(IonEngine::Events::EventType::WindowClosed == e.getType()) {
            running = false;
        }
        
        IonEngine::Events::EventDispatcher dispatcher(e);

        auto eventfn = [](IonEngine::Events::KeyPressedEvent& e) -> bool {
            if(IonEngine::Input::Key::Q == e.key) {
                //auto [x, y] = IonEngine::Input::InputState::getMousePosition();
                //ION_LOG_INFO("Polled position: {} {}", x, y);
                ION_LOG_INFO("e is down: {}", IonEngine::Input::InputState::isKeyPressed(IonEngine::Input::Key::E));
            }
            return true;
        };

        dispatcher.dispatch<IonEngine::Events::KeyPressedEvent>(eventfn);

        return true;
    }

private:
    std::unique_ptr<IonEngine::Window> m_window = nullptr;
    bool running = true;
};

IonEngine::Application* getApplication()
{
    return new IonEditor;
}

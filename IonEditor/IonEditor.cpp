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

    bool onEvent(IonEngine::Event& e)
    {
        ION_LOG_INFO("{}", e);
        if(IonEngine::EventType::WindowClosed == e.getType()) {
            running = false;
        }

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

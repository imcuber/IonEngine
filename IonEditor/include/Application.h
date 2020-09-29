#ifndef IONEDITOR_APPLICATION_H
#define IONEDITOR_APPLICATION_H

#include <IonEngine.h>

class IonEditor: public IonEngine::Application
{
public:
    IonEditor();

    virtual ~IonEditor() noexcept override = default;

    virtual void onEvent(IonEngine::Event& e) override;
    virtual bool isRunning() override;
    virtual void onUpdate() override;
    virtual void onRender() override;

private:
    std::unique_ptr<IonEngine::Window> m_window = nullptr;
    bool m_running = true;
};

#endif // IONEDITOR_APPLICATION_H
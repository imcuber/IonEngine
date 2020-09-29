#include <IonEngine.h>

#include <utility>

namespace IonEngine {

    void Application::run()
    {
        onEvent(IonEngine::AppStartedEvent{});
        while(isRunning()) {
            onEvent(IonEngine::AppTickEvent{});

            onUpdate();
            onEvent(IonEngine::AppUpdatedEvent{});

            m_layerStack.onImGuiRender();

            onRender();
            onEvent(IonEngine::AppRenderedEvent{});
        }
        onEvent(IonEngine::AppStoppedEvent{});
    }

    void Application::pushLayer(std::unique_ptr<Layer>&& layer)
    {
        layer->onAttach();
        m_layerStack.pushLayer(std::move(layer));
    }

    void Application::onEvent(IonEngine::Event& e)
    {
        m_layerStack.onEvent(e);
    }

    void Application::onUpdate()
    {
        m_layerStack.onUpdate();
    }

    void Application::onRender()
    {
        m_layerStack.onRender();
    }

}

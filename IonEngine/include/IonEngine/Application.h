#ifndef IONENGINE_APPLICATION_H
#define IONENGINE_APPLICATION_H

#include <IonEngine/Events.h>
#include <IonEngine/LayerStack.h>

namespace IonEngine {

    class Application
    {
    public:
        Application() = default;
        virtual ~Application() noexcept = default;

        void run();
        void pushLayer(std::unique_ptr<Layer>&& layer);

        virtual void onEvent(IonEngine::Event& e);
        virtual bool isRunning() = 0;
        virtual void onUpdate();
        virtual void onRender();

    private:
        LayerStack m_layerStack;
    };

}

#endif // IONENGINE_APPLICATION_H

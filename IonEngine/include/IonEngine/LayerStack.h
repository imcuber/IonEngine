#ifndef IONENGINE_LAYERSTACK_H
#define IONENGINE_LAYERSTACK_H

#include <IonEngine/Events.h>

namespace IonEngine {

    class Layer
    {
    public:
        virtual ~Layer() noexcept = default;
    
        virtual void onAttach() = 0;
        virtual void onEvent(IonEngine::Event& e) = 0;
        virtual void onUpdate() = 0;
        virtual void onRender() = 0;
        virtual void onImGuiRender() = 0;

    protected:
        Layer() noexcept = default;
    };

    class LayerStack
    {
    public:
        LayerStack() = default;
        ~LayerStack() = default;

        void onEvent(IonEngine::Event& e);
        void onUpdate();
        void onRender();
        void onImGuiRender();
        
        void pushLayer(std::unique_ptr<Layer>&& layer);
        
    private:
        std::vector<std::unique_ptr<Layer>> m_layers;
    };
}

#endif // IONENGINE_LAYERSTACK_H

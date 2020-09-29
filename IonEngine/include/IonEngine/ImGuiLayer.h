#ifndef IONENGINE_IMGUILAYER_H
#define IONENGINE_IMGUILAYER_H

#include <IonEngine/LayerStack.h>

#include <memory>

namespace IonEngine {

    class ImGuiLayer: public Layer
    {
    public:
        ImGuiLayer() = default;
        virtual ~ImGuiLayer() noexcept = default;

        virtual void onAttach() override;
        virtual void onEvent(IonEngine::Event& e) override;
        virtual void onUpdate() override;
        virtual void onRender() override;
        virtual void onImGuiRender() override;
    
    protected:
        virtual void onUpdateImpl();
        virtual void onRenderImpl();

    protected:
        friend class IonEngine::Graphics::Context;

        static std::unique_ptr<ImGuiLayer> create();
        static std::unique_ptr<ImGuiLayer> m_instance;
    };

}

#endif // IONENGINE_IMGUILAYER_H

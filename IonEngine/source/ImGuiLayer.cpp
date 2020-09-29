#include <IonEngine.h>

#include <imgui.h>

namespace IonEngine {
    
    std::unique_ptr<ImGuiLayer> ImGuiLayer::m_instance = ImGuiLayer::create();

    std::unique_ptr<ImGuiLayer> ImGuiLayer::create()
    {
        switch(IonEngine::API::getGraphicsAPI()) {
        case IonEngine::GraphicsAPI::OpenGL:
        {
            return std::make_unique<IonEngine::Platform::OpenGLImGuiLayer>();
            break;
        }
        default:
        {
            ION_CORE_ASSERT(false, "API is not supported");
        }
        }
    }

    void ImGuiLayer::onAttach()
    {}

    void ImGuiLayer::onEvent(IonEngine::Event& e)
    {
        if(!e.isInCategory(EventCategory::Input)) {
            return;
        }

        ImGuiIO& io = ImGui::GetIO();
        
        if(e.isInCategory(EventCategory::Keyboard) && io.WantCaptureKeyboard 
           || e.isInCategory(EventCategory::Mouse) && io.WantCaptureMouse) {
            e.handled = true;
            return;
        }
        
        if(e.getType() == EventType::CharInput && io.WantTextInput) {
            e.handled = true;
            return;
        }

    }

    void ImGuiLayer::onUpdate()
    {
        m_instance->onUpdateImpl();
    }
    
    void ImGuiLayer::onRender()
    {
        m_instance->onRenderImpl();
    }
    
    void ImGuiLayer::onImGuiRender()
    {}

    void ImGuiLayer::onUpdateImpl()
    {}

    void ImGuiLayer::onRenderImpl()
    {}

}

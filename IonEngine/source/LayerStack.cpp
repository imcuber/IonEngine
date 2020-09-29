#include <IonEngine.h>

namespace IonEngine {

    void LayerStack::onEvent(IonEngine::Event& e)
    {
        for(auto rit = std::rbegin(m_layers); rit < std::rend(m_layers); ++rit) {
            if(e.handled) {
                break;
            }
            rit->get()->onEvent(e);
        }
    }

    void LayerStack::onUpdate()
    {
        for(auto& l : m_layers) {
            l->onUpdate();
        }
    }

    void LayerStack::onRender()
    {
        for(auto it = std::begin(m_layers); it < std::end(m_layers); ++it) {
            it->get()->onRender();
        }
    }

    void LayerStack::onImGuiRender()
    {
        for(auto it = std::begin(m_layers); it < std::end(m_layers); ++it) {
            it->get()->onImGuiRender();
        }
    }

    void LayerStack::pushLayer(std::unique_ptr<Layer>&& layer)
    {
        m_layers.emplace_back(std::move(layer));
    }

}

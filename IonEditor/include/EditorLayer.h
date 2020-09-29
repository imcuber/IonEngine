#ifndef IONEDITOR_EDITORLAYER_H
#define IONEDITOR_EDITORLAYER_H

#include <IonEngine.h>

#include <glad/glad.h>

class EditorLayer: public IonEngine::Layer
{
public:
    EditorLayer();
    virtual ~EditorLayer() noexcept override = default;

    virtual void onAttach() override;
    virtual void onEvent(IonEngine::Event& e) override;
    virtual void onUpdate() override;
    virtual void onRender() override;
    virtual void onImGuiRender() override;

private:
    std::unique_ptr<IonEngine::Shader> m_shader;
    std::unique_ptr<IonEngine::VertexArray> m_vao;
};

#endif // IONEDITOR_EDITORLAYER_H

#include "Application.h"
#include "EditorLayer.h"

#include <filesystem>

IonEditor::IonEditor()
{
    auto cwd = std::filesystem::current_path().string();
    ION_LOG_INFO("Current working directory: {}", cwd);

    m_window = IonEngine::Window::create();
    m_window->setEventCallback([this](IonEngine::Events::Event& event) {
        this->onEvent(event);
        return true;
    });

    pushLayer(std::make_unique<EditorLayer>());
    pushLayer(std::make_unique<IonEngine::ImGuiLayer>());
}

void IonEditor::onEvent(IonEngine::Event& e)
{
    Application::onEvent(e);

    if(!e.handled && IonEngine::EventType::WindowClosed == e.getType()) {
        m_running = false;
    }
}

bool IonEditor::isRunning()
{
    return m_running;
}

void IonEditor::onUpdate()
{
    Application::onUpdate();
    m_window->onUpdate();
}

void IonEditor::onRender()
{
    Application::onRender();
    m_window->onRender();
}

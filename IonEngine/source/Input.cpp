#include <IonEngine.h>

#include <memory>

namespace IonEngine::Input {

    IonEngine::Window* InputState::m_window = nullptr;
    std::unique_ptr<InputState> InputState::m_instance = nullptr;

    bool InputState::isKeyPressed(Key key) noexcept
    {
        ION_CORE_ASSERT(nullptr != m_instance, "InputState is not initialized");
        return m_instance->isKeyPressedImpl(key);
    }

    bool InputState::isMouseButtonPressed(MouseButton button) noexcept
    {
        ION_CORE_ASSERT(nullptr != m_instance, "InputState is not initialized");
        return m_instance->isMouseButtonPressedImpl(button);
    }

    MousePosition InputState::getMousePosition() noexcept
    {
        ION_CORE_ASSERT(nullptr != m_instance, "InputState is not initialized");
        return m_instance->getMousePositionImpl();
    }

}

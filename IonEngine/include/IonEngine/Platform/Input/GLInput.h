#ifndef IONENGINE_PLATFORM_INPUT_GLINPUT_H
#define IONENGINE_PLATFORM_INPUT_GLINPUT_H

#include <IonEngine/Input.h>

namespace IonEngine::Platform {

    class GLInput: public IonEngine::Input::InputState
    {
    public:
        GLInput() = default;

    protected:
        virtual bool isKeyPressedImpl(Key key) noexcept override;
        virtual bool isMouseButtonPressedImpl(MouseButton button) noexcept override;
        virtual MousePosition getMousePositionImpl() noexcept override;
    };
}

#endif // IONENGINE_PLATFORM_INPUT_GLINPUT_H

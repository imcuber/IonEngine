#ifndef IONENGINE_PLATFORM_OPENGL_OPENGLIMGUILAYER_H
#define IONENGINE_PLATFORM_OPENGL_OPENGLIMGUILAYER_H

#include <IonEngine/ImGuiLayer.h>

namespace IonEngine::Platform {

    class OpenGLImGuiLayer: public ImGuiLayer
    {
    public:
        OpenGLImGuiLayer() = default;
        virtual ~OpenGLImGuiLayer() noexcept = default;

    protected:
        virtual void onUpdateImpl() override;
        virtual void onRenderImpl() override;
    };

}

#endif // IONENGINE_PLATFORM_OPENGL_OPENGLIMGUILAYER_H

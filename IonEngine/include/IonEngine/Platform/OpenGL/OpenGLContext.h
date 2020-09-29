#ifndef IONENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_H
#define IONENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_H

namespace IonEngine::Platform {

    class OpenGLContext: public IonEngine::Graphics::Context
    {
    public:
        struct OpenGLInfo
        {
            GLint major = 0;
            GLint minor = 0;
            char* vendor = nullptr;
            char* renderer = nullptr;
            char* glslVersion = nullptr;
        };

    public:
        OpenGLContext(IonEngine::Window& window);

        virtual ~OpenGLContext() noexcept override = default;

        virtual void swapBuffers() override;

    private:
        GLFWwindow* m_handle;
        OpenGLInfo m_info;
    };

}

#endif // IONENGINE_PLATFORM_OPENGL_OPENGLCONTEXT_H


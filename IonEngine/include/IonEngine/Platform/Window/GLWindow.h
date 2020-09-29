#include <IonEngine.h>

#include <glad/glad.h>
#include <glfw/glfw3.h>

namespace IonEngine::Platform {

    class GLWindow: public IonEngine::Window
    {
    public:
        GLWindow(const WindowProps& props);

        virtual ~GLWindow() noexcept override;

        virtual bool setVSync(bool value) noexcept override;

        virtual void onUpdate() override;
        virtual void onRender() override;

        virtual void* getNativeHandler() const noexcept override;

    private:
        void setCallbacks() noexcept;

    private:

        GLFWwindow* m_handle = nullptr;
    };

}

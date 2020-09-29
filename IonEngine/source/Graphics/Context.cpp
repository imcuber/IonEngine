#include <IonEngine.h>

namespace IonEngine::Graphics {

    Context::Context(IonEngine::Window& window):
        m_window{ window }
    {}

    std::unique_ptr<Context> Context::create(IonEngine::Window& window)
    {
        switch(IonEngine::API::getGraphicsAPI()) {
        case IonEngine::GraphicsAPI::OpenGL:
        {
            return std::make_unique<IonEngine::Platform::OpenGLContext>(window);
            break;
        }
        default:
        {
            ION_CORE_ASSERT(false, "API is not supported");
        }
        }
    }
}

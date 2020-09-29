#include <IonEngine.h>

namespace IonEngine::Graphics {

    Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource):
        m_vertexSource{ vertexSource },
        m_fragmentSource{ fragmentSource }
    {}

    std::unique_ptr<Shader> Shader::create(const std::string& vertexSource, const std::string& fragmentSource)
    {
        switch(IonEngine::API::getGraphicsAPI()) {
        case IonEngine::GraphicsAPI::OpenGL:
        {
            return std::make_unique<IonEngine::Platform::OpenGLShader>(vertexSource, fragmentSource);
            break;
        }
        default:
        {
            ION_CORE_ASSERT(false, "API is not supported");
        }
        }
    }

}

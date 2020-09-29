#include <IonEngine.h>

namespace IonEngine::Platform {

    API::GraphicsAPI API::m_graphicsAPI = API::GraphicsAPI::OpenGL;

    GraphicsAPI API::getGraphicsAPI()
    {
        return m_graphicsAPI;
    }

}

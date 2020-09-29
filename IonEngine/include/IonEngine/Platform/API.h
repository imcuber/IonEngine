#ifndef IONENGINE_PLATFORM_API_H
#define IONENGINE_PLATFORM_API_H

namespace IonEngine::Platform {

    class API
    {
    public:
        enum class GraphicsAPI
        {
            None = 0,
            OpenGL
        };

    public:
        static GraphicsAPI getGraphicsAPI();

    private:
        API() = default;

    private:
        static GraphicsAPI m_graphicsAPI;
    };
}

namespace IonEngine {

    using API = IonEngine::Platform::API;
    using GraphicsAPI = IonEngine::Platform::API::GraphicsAPI;

}

#endif // IONENGINE_PLATFORM_API_H

#ifndef IONENGINE_GRAPHICS_SHADER_H
#define IONENGINE_GRAPHICS_SHADER_H

#include <IonEngine/extern/glm.h>

#include <string>
#include <memory>

namespace IonEngine::Graphics {

    class Shader: public IonEngine::NonCopyable
    {
    public:
        static std::unique_ptr<Shader> create(const std::string& vertexSource, const std::string& fragmentSource);
        virtual ~Shader() noexcept = default;

        virtual void bind() = 0;
        virtual void unbind() = 0;

    protected:
        Shader(const std::string& vertexSource, const std::string& fragmentSource);

    protected:
        std::string m_vertexSource;
        std::string m_fragmentSource;
    };

}

namespace IonEngine {

    using Shader = IonEngine::Graphics::Shader;

}

#endif // IONENGINE_GRAPHICS_SHADER_H

#ifndef IONENGINE_PLATFORM_OPENGL_OPENGLSHADER_H
#define IONENGINE_PLATFORM_OPENGL_OPENGLSHADER_H

#include <IonEngine/Graphics/Shader.h>

#include <glad/glad.h>

namespace IonEngine::Platform {

    class OpenGLShader: public IonEngine::Graphics::Shader
    {
    public:
        struct ShaderStage
        {
            GLuint handler = 0;

            ShaderStage(GLuint handler);
            ~ShaderStage();
        };

    public:
        OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource);

        ShaderStage compileShaderStage(std::string& source, GLenum stage);

        GLuint linkProgram(const ShaderStage& vertexStage, const ShaderStage& fragmentStage);

        virtual void bind() override;

        virtual void unbind() override;

    private:
        GLuint m_handler;
    };

}

#endif // IONENGINE_PLATFORM_OPENGL_OPENGLSHADER_H

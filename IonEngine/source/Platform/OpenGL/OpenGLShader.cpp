#include <IonEngine.h>

#include <glad/glad.h>

namespace IonEngine::Platform {

    OpenGLShader::ShaderStage::ShaderStage(GLuint handler):
        handler{ handler }
    {}

    OpenGLShader::ShaderStage::~ShaderStage()
    {
        if(0 != handler) {
            glDeleteShader(handler);
        }
    }

    OpenGLShader::OpenGLShader(const std::string& vertexSource, const std::string& fragmentSource):
        Shader{ vertexSource, fragmentSource }
    {
        auto vertexStage = compileShaderStage(m_vertexSource, GL_VERTEX_SHADER);
        auto fragmentStage = compileShaderStage(m_fragmentSource, GL_FRAGMENT_SHADER);

        m_handler = linkProgram(vertexStage, fragmentStage);
        if(0 == m_handler) {
            throw;
        }
    }

    OpenGLShader::ShaderStage OpenGLShader::compileShaderStage(std::string& source, GLenum stage)
    {
        GLuint handler = glCreateShader(stage);
        const char* src_data = source.data();
        glShaderSource(handler, 1, &src_data, nullptr);
        glCompileShader(handler);

        GLint compileStatus = 0;
        glGetShaderiv(handler, GL_COMPILE_STATUS, &compileStatus);
        if(GL_TRUE != compileStatus) {
            GLint maxLength = 0;
            glGetShaderiv(handler, GL_INFO_LOG_LENGTH, &maxLength);

            auto compileError = std::make_unique<char[]>(maxLength);
            glGetShaderInfoLog(handler, maxLength, nullptr, compileError.get());

            ION_CORE_LOG_ERROR("Shader compilation error: {}", compileError.get());
            glDeleteShader(handler);

            return ShaderStage{ 0 };
        }
        return ShaderStage{ handler };
    }

    GLuint OpenGLShader::linkProgram(const ShaderStage& vertexStage, const ShaderStage& fragmentStage)
    {
        GLuint handler = glCreateProgram();
        glAttachShader(handler, vertexStage.handler);
        glAttachShader(handler, fragmentStage.handler);
        glLinkProgram(handler);

        GLint linkStatus = 0;
        glGetProgramiv(handler, GL_LINK_STATUS, &linkStatus);
        if(GL_TRUE != linkStatus) {
            GLint maxLength = 0;
            glGetProgramiv(handler, GL_INFO_LOG_LENGTH, &maxLength);

            auto linkError = std::make_unique<char[]>(maxLength);
            glGetProgramInfoLog(handler, maxLength, nullptr, linkError.get());

            ION_CORE_LOG_ERROR("Shader link error: {}", linkError.get());

            glDeleteProgram(handler);
            return 0;
        }
        return handler;
    }

    void OpenGLShader::bind()
    {
        glUseProgram(m_handler);
    }

    void OpenGLShader::unbind()
    {
        glUseProgram(0);
    }

}

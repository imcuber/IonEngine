#ifndef IONENGINE_PLATFORM_OPENGL_OPENGLBUFFER_H
#define IONENGINE_PLATFORM_OPENGL_OPENGLBUFFER_H

#include <IonEngine/Graphics/Buffer.h>

#include <glad/glad.h>

namespace IonEngine::Platform {

    class OpenGLBufferLayout: public IonEngine::Graphics::BufferLayout
    {
    public:
        OpenGLBufferLayout(const std::initializer_list<BufferElement>& elements);
        virtual ~OpenGLBufferLayout() noexcept override = default;

        virtual void bind() override;
        virtual void unbind() override;
    };

    class OpenGLVertexBuffer: public IonEngine::Graphics::VertexBuffer 
    {
    public:
        OpenGLVertexBuffer(const void* data, size_t size, const std::shared_ptr<BufferLayout>& layout);
        virtual ~OpenGLVertexBuffer() noexcept override;

        virtual void bind() override;
        virtual void unbind() override;
    
    private:
        GLuint m_handle;
    };

    class OpenGLIndexBuffer: public IonEngine::Graphics::IndexBuffer
    {
    public:
        OpenGLIndexBuffer(const std::vector<uint32_t>& indices, size_t count = 0);
        virtual ~OpenGLIndexBuffer() noexcept override;

        virtual void bind() override;
        virtual void unbind() override;

    private:
        GLuint m_handle;
    };

    class OpenGLVertexArray: public IonEngine::Graphics::VertexArray
    {
    public:
        OpenGLVertexArray(const std::shared_ptr<VertexBuffer>& vertices, const std::shared_ptr<IndexBuffer>& indices);
        virtual ~OpenGLVertexArray() noexcept override;

        virtual void bind() override;
        virtual void unbind() override;

    private:
        GLuint m_handle;
    };

}

#endif // IONENGINE_PLATFORM_OPENGL_OPENGLBUFFER_H

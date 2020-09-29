#include <IonEngine.h>

#include <glad/glad.h>

namespace IonEngine::Platform {

    OpenGLBufferLayout::OpenGLBufferLayout(const std::initializer_list<BufferElement>& elements):
        BufferLayout{ elements }
    {}

    GLenum bufferDataTypeToGLType(BufferDataType type)
    {
        switch(type) {
        case BufferDataType::Float: 
        case BufferDataType::Float2:
        case BufferDataType::Float3:
        case BufferDataType::Float4:
        case BufferDataType::Mat3:  
        case BufferDataType::Mat4:  
            return GL_FLOAT;
        case BufferDataType::Int: 
        case BufferDataType::Int2:
        case BufferDataType::Int3:
        case BufferDataType::Int4:
            return GL_INT;
        case BufferDataType::UInt: 
        case BufferDataType::UInt2:
        case BufferDataType::UInt3:
        case BufferDataType::UInt4:
            return GL_UNSIGNED_INT;
        default:
            ION_CORE_ASSERT(false, "Unknown BufferDataType");
        }
    }

    GLint bufferDataTypeGLSize(BufferDataType type)
    {
        switch(type) {
        case BufferDataType::Float:     
        case BufferDataType::Int:       
        case BufferDataType::UInt:      
            return 1;
        case BufferDataType::Float2:    
        case BufferDataType::Int2:      
        case BufferDataType::UInt2:     
            return 2;
        case BufferDataType::Float3:    
        case BufferDataType::Int3:      
        case BufferDataType::UInt3:     
            return 3;
        case BufferDataType::Float4:    
        case BufferDataType::Int4:      
        case BufferDataType::UInt4:     
            return 4;
        case BufferDataType::Mat3:      
        case BufferDataType::Mat4:      
            ION_CORE_ASSERT(false, "Matrix data types not supported yet");
        default:
            ION_CORE_ASSERT(false, "Unknown BufferDataType");
        }
    }

    void OpenGLBufferLayout::bind()
    {
        size_t idx = 0;
        for(auto& e : m_elements) {
            glEnableVertexAttribArray(idx);
            glVertexAttribPointer(idx, 
                                  bufferDataTypeGLSize(e.type), 
                                  bufferDataTypeToGLType(e.type),
                                  e.normalized ? GL_TRUE : GL_FALSE,
                                  e.getStride(), 
                                  (const void*)e.getOffset());
            idx++;
        }
    }

    void OpenGLBufferLayout::unbind()
    {
        size_t idx = 0;
        for(auto& e : m_elements) {
            glDisableVertexAttribArray(idx);
            idx++;
        }
    }

    OpenGLVertexBuffer::OpenGLVertexBuffer(const void* data, size_t size, const std::shared_ptr<BufferLayout>& layout):
        VertexBuffer{ data, size, layout }
    {
        glCreateBuffers(1, &m_handle);
        ION_CORE_ASSERT(0 != m_handle, "Couldn't create buffer");

        glNamedBufferData(m_handle, size, data, GL_STATIC_DRAW);
    }

    OpenGLVertexBuffer::~OpenGLVertexBuffer()
    {
        glDeleteBuffers(1, &m_handle);
    }

    void OpenGLVertexBuffer::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, m_handle);
    }

    void OpenGLVertexBuffer::unbind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    OpenGLIndexBuffer::OpenGLIndexBuffer(const std::vector<uint32_t>& indices, size_t count):
        IndexBuffer{ indices, count }
    {
        glCreateBuffers(1, &m_handle);
        ION_CORE_ASSERT(0 != m_handle, "Couldn't create buffer");

        glNamedBufferData(m_handle, std::size(m_indices) * sizeof(uint32_t), m_indices.data(), GL_STATIC_DRAW);
    }

    OpenGLIndexBuffer::~OpenGLIndexBuffer()
    {
        glDeleteBuffers(1, &m_handle);
    }

    void OpenGLIndexBuffer::bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_handle);
    }

    void OpenGLIndexBuffer::unbind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    OpenGLVertexArray::OpenGLVertexArray(const std::shared_ptr<VertexBuffer>& vertices, const std::shared_ptr<IndexBuffer>& indices):
        VertexArray{ vertices, indices }
    {
        glCreateVertexArrays(1, &m_handle);
        ION_CORE_ASSERT(0 != m_handle, "Couldn't create vertex array");

        GLint currentVAO = 0;
        glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &currentVAO);

        glBindVertexArray(m_handle);

        m_indices->bind();
        m_vertices->bind();
        m_vertices->getLayout()->bind();

        glBindVertexArray(currentVAO);
    }

    OpenGLVertexArray::~OpenGLVertexArray()
    {
        glDeleteVertexArrays(1, &m_handle);
    }

    void OpenGLVertexArray::bind()
    {
        glBindVertexArray(m_handle);
    }

    void OpenGLVertexArray::unbind()
    {
        glBindVertexArray(0);
    }
}

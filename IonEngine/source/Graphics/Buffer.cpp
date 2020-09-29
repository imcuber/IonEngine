#include <IonEngine.h>

namespace IonEngine::Graphics {

    size_t bufferDataTypeSize(BufferDataType type)
    {
        switch(type) {
        case BufferDataType::Float:     return 1 * sizeof(float);
        case BufferDataType::Float2:    return 2 * sizeof(float);
        case BufferDataType::Float3:    return 3 * sizeof(float);
        case BufferDataType::Float4:    return 4 * sizeof(float);
        case BufferDataType::Mat3:      return 9 * sizeof(float);
        case BufferDataType::Mat4:      return 16 * sizeof(float);
        case BufferDataType::Int:       return 1 * sizeof(int);
        case BufferDataType::Int2:      return 2 * sizeof(int);
        case BufferDataType::Int3:      return 3 * sizeof(int);
        case BufferDataType::Int4:      return 4 * sizeof(int);
        case BufferDataType::UInt:      return 1 * sizeof(unsigned int);
        case BufferDataType::UInt2:     return 2 * sizeof(unsigned int);
        case BufferDataType::UInt3:     return 3 * sizeof(unsigned int);
        case BufferDataType::UInt4:     return 4 * sizeof(unsigned int);
        default:
            ION_CORE_ASSERT(false, "Unknown BufferDataType");
        }
    }

    BufferElement::BufferElement(BufferDataType type, const std::string& name, bool normalized):
        type{ type },
        name{ name },
        normalized{ normalized },
        m_size{ bufferDataTypeSize(type) },
        m_offset{ 0 },
        m_stride{ 0 }
    {}

    
    const size_t& BufferElement::getSize() const
    {
        return m_size;
    }

    const size_t& BufferElement::getOffset() const
    {
        return m_offset;
    }

    const size_t& BufferElement::getStride() const
    {
        return m_stride;
    }

    BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements):
        m_elements{ elements }
    {
        evaluateElementParameters();
    }

    void BufferLayout::evaluateElementParameters()
    {
        size_t currentOffset = 0;
        for(auto& e : m_elements) {
            e.m_offset = currentOffset;
            currentOffset += e.m_size;
        }

        size_t stride = currentOffset;
        for(auto& e : m_elements) {
            e.m_stride = stride;
        }
    }

    std::unique_ptr<BufferLayout> BufferLayout::create(const std::initializer_list<BufferElement>& elements)
    {
        switch(IonEngine::API::getGraphicsAPI()) {
        case IonEngine::GraphicsAPI::OpenGL:
            return std::make_unique<IonEngine::Platform::OpenGLBufferLayout>(elements);
        default:
            ION_CORE_ASSERT(false, "Unsupported Graphics API");
        }
        return nullptr;
    }

    std::unique_ptr<VertexBuffer> VertexBuffer::create(const void* data, size_t size, const std::shared_ptr<BufferLayout>& layout)
    {
        switch(IonEngine::API::getGraphicsAPI()) {
        case IonEngine::GraphicsAPI::OpenGL:
            return std::make_unique<IonEngine::Platform::OpenGLVertexBuffer>(data, size, layout);
        default:
            ION_CORE_ASSERT(false, "Unsupported Graphics API");
        }
        return nullptr;
    }

    VertexBuffer::VertexBuffer(const void* data, size_t size, const std::shared_ptr<BufferLayout>& layout):
        m_layout{ layout }
    {}

    const std::shared_ptr<BufferLayout>& VertexBuffer::getLayout() const
    {
        return m_layout;
    }

    std::unique_ptr<IndexBuffer> IndexBuffer::create(const std::vector<uint32_t>& indices, size_t count)
    {
        switch(IonEngine::API::getGraphicsAPI()) {
        case IonEngine::GraphicsAPI::OpenGL:
            return std::make_unique<IonEngine::Platform::OpenGLIndexBuffer>(indices, count);
        default:
            ION_CORE_ASSERT(false, "Unsupported Graphics API");
        }
        return nullptr;
    }

    IndexBuffer::IndexBuffer(const std::vector<uint32_t>& indices, size_t count):
        m_indices{ std::begin(indices), 0 == count ? std::end(indices) : std::begin(indices) + count }
    {}

    const size_t& IndexBuffer::getCount() const
    {
        return std::size(m_indices);
    }

    std::unique_ptr<VertexArray> VertexArray::create(const std::shared_ptr<VertexBuffer>& vertices, const std::shared_ptr<IndexBuffer>& indices)
    {
        switch(IonEngine::API::getGraphicsAPI()) {
        case IonEngine::GraphicsAPI::OpenGL:
            return std::make_unique<IonEngine::Platform::OpenGLVertexArray>(vertices, indices);
        default:
            ION_CORE_ASSERT(false, "Unsupported Graphics API");
        }
        return nullptr;
    }

    VertexArray::VertexArray(const std::shared_ptr<VertexBuffer>& vertices, const std::shared_ptr<IndexBuffer>& indices):
        m_vertices{ vertices },
        m_indices{ indices }
    {}

    const std::shared_ptr<VertexBuffer>& VertexArray::getVertices() const
    {
        return m_vertices;
    }

    const std::shared_ptr<IndexBuffer>& VertexArray::getIndices() const
    {
        return m_indices;
    }
}

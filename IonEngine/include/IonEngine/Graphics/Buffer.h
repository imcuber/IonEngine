#ifndef IONENGINE_GRAPHICS_BUFFER_H
#define IONENGINE_GRAPHICS_BUFFER_H

#include <initializer_list>

namespace IonEngine::Graphics {
    
    enum class BufferDataType
    {
        Unknown,
        Float, Float2, Float3, Float4,
        Mat3, Mat4,
        Int, Int2, Int3, Int4, UInt, UInt2, UInt3, UInt4
    };

    size_t bufferDataTypeSize(BufferDataType type);

    struct BufferElement
    {
    public:
        BufferDataType type;
        std::string name;
        bool normalized;

    public:
        BufferElement(BufferDataType type, const std::string& name = "Unknown", bool normalized = false);
        ~BufferElement() noexcept = default;

    public:
        const size_t& getSize() const;
        const size_t& getOffset() const;
        const size_t& getStride() const;

    private:
        friend class BufferLayout;
        size_t m_size = 0;
        size_t m_offset = 0;
        size_t m_stride = 0;
    };

    class BufferLayout
    {
    public:
        static std::unique_ptr<BufferLayout> create(const std::initializer_list<BufferElement>& elements);
        virtual ~BufferLayout() noexcept = default;

        virtual void bind() = 0;
        virtual void unbind() = 0;

    protected:
        BufferLayout(const std::initializer_list<BufferElement>& elements);

    protected:
        std::vector<BufferElement> m_elements;

    private:
        void evaluateElementParameters();
    };

    class VertexBuffer: public NonCopyable
    {
    public:
        static std::unique_ptr<VertexBuffer> create(const void* data, size_t size, const std::shared_ptr<BufferLayout>& layout);
        virtual ~VertexBuffer() noexcept = default;

        const std::shared_ptr<BufferLayout>& getLayout() const;

        virtual void bind() = 0;
        virtual void unbind() = 0;

    protected:
        VertexBuffer(const void* data, size_t size, const std::shared_ptr<BufferLayout>& layout);

    protected:
        std::shared_ptr<BufferLayout> m_layout;
    };

    class IndexBuffer: public NonCopyable
    {
    public:
        static std::unique_ptr<IndexBuffer> create(const std::vector<uint32_t>& indices, size_t count = 0);
        virtual ~IndexBuffer() noexcept = default;

        const size_t& getCount() const;

        virtual void bind() = 0;
        virtual void unbind() = 0;

    protected:
        IndexBuffer(const std::vector<uint32_t>& indices, size_t count = 0);

    protected:
        std::vector<uint32_t> m_indices;
    };

    class VertexArray: public NonCopyable
    {
    public:
        static std::unique_ptr<VertexArray> create(const std::shared_ptr<VertexBuffer>& vertices, const std::shared_ptr<IndexBuffer>& indices);
        virtual ~VertexArray() noexcept = default;

        virtual void bind() = 0;
        virtual void unbind() = 0;

        const std::shared_ptr<VertexBuffer>& getVertices() const;
        const std::shared_ptr<IndexBuffer>& getIndices() const;

    protected:
        VertexArray(const std::shared_ptr<VertexBuffer>& vertices, const std::shared_ptr<IndexBuffer>& indices);

    protected:
        std::shared_ptr<VertexBuffer> m_vertices;
        std::shared_ptr<IndexBuffer> m_indices;
    };

}

namespace IonEngine {

    using BufferDataType = IonEngine::Graphics::BufferDataType;
    using BufferElement = IonEngine::Graphics::BufferElement;
    using BufferLayout = IonEngine::Graphics::BufferLayout;
    using VertexBuffer = IonEngine::Graphics::VertexBuffer;
    using IndexBuffer = IonEngine::Graphics::IndexBuffer;
    using VertexArray = IonEngine::Graphics::VertexArray;
}

#endif // IONENGINE_GRAPHICS_BUFFER_H

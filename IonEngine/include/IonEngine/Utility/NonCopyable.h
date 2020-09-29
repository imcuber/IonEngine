#ifndef IONENGINE_UTILITY_NONCOPYABLE_H
#define IONENGINE_UTILITY_NONCOPYABLE_H

namespace IonEngine::Utility {

    class NonCopyable
    {
    public:
        NonCopyable() noexcept = default;

    private:
        NonCopyable(NonCopyable& that) = delete;
        void operator=(NonCopyable& that) = delete;
    };

}

namespace IonEngine {

    using NonCopyable = IonEngine::Utility::NonCopyable;

}

#endif // IONENGINE_UTILITY_NONCOPYABLE_H

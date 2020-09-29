#ifndef IONENGINE_GRAPHICS_CONTEXT_H
#define IONENGINE_GRAPHICS_CONTEXT_H

#include <IonEngine/Window.h>

namespace IonEngine::Graphics {

    class Context: public IonEngine::NonCopyable
    {
    public:
        static std::unique_ptr<Context> create(IonEngine::Window& window);

        virtual ~Context() = default;
    
        virtual void swapBuffers() = 0;

    protected:
        Context(IonEngine::Window& window);
    
    protected:
        IonEngine::Window& m_window;
    };

}

namespace IonEngine {

    using Context = IonEngine::Graphics::Context;

}

#endif // IONENGINE_GRAPHICS_CONTEXT_H

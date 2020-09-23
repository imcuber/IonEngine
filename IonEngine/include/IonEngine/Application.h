#ifndef IONENGINE_APPLICATION_H
#define IONENGINE_APPLICATION_H

namespace IonEngine {

    class Application
    {
    public:
        Application() = default;
        virtual ~Application() noexcept = default;

        virtual void run(int argc, char *argv[]) = 0;
    };

}

#endif // IONENGINE_APPLICATION_H

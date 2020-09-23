#include <IonEngine.h>

class IonPlayer: public IonEngine::Application
{
public:
    IonPlayer() = default;
    virtual ~IonPlayer() noexcept override = default;
    virtual void run(int argc, char* argv[]) override
    {}
};

IonEngine::Application* getApplication()
{
    while(true) {
        auto var = 1;
        ION_LOG_INFO("getApplication, var = {}", var);
    }
    return new IonPlayer;
}

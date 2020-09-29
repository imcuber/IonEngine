#include <IonEngine.h>

#include "Application.h"


std::unique_ptr<IonEngine::Application> getApplication(int argc, char* argv[])
{
    return std::make_unique<IonEditor>();
}

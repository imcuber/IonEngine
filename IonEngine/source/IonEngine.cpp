#include <IonEngine.h>

int main(int argc, char* argv[])
{
    auto application = getApplication();
    application->run(argc, argv);
    delete application;
    return 0;
}

namespace IonEngine {

}

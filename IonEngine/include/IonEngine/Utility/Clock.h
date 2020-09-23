#ifndef IONENGINE_UTILITY_CLOCK_H
#define IONENGINE_UTILITY_CLOCK_H

#include <memory>
#include <chrono>

namespace IonEngine::Utility {

    class Clock
    {
    public:
        static std::chrono::system_clock::duration getTime();
        static std::chrono::system_clock::duration getLocalTime();

    private:
        Clock() = default;
        ~Clock() = default;
    };

}

#endif // IONENGINE_UTILITY_CLOCK_H

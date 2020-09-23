#include <IonEngine.h>

#include <ctime>

namespace IonEngine::Utility {

    std::chrono::system_clock::duration Clock::getLocalTime()
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        if(nullptr == std::localtime(&time)) {
            ION_CORE_LOG_ERROR("Unable to convert time point to local time");
        }
        return std::chrono::system_clock::from_time_t(time).time_since_epoch();
    }

    std::chrono::system_clock::duration Clock::getTime()
    {
        auto time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        return std::chrono::system_clock::from_time_t(time).time_since_epoch();
    }

}

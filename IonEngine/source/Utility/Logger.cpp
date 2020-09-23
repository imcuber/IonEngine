#include <IonEngine.h>

namespace IonEngine::Utility {

    std::unique_ptr<Logger> Logger::s_engineLogger = nullptr;
    std::unique_ptr<Logger> Logger::s_clientLogger = nullptr;

    void Logger::init()
    {
        if(nullptr == s_engineLogger) {
            s_engineLogger = std::make_unique<Logger>("IonEngine");
        }
        if(nullptr == s_clientLogger) {
            s_clientLogger = std::make_unique<Logger>("IonClient");
        }
    }

    Logger::Logger(const std::string& name):
        m_name{ name }
    {}

    Logger& Logger::getEngineLogger()
    {
        if(nullptr == s_engineLogger) {
            init();
        }

        return *s_engineLogger;
    }

    Logger& Logger::getClientLogger()
    {
        if(nullptr == s_clientLogger) {
            init();
        }

        return *s_clientLogger;
    }

}
#ifndef IONENGINE_UTILITY_LOGGER_H
#define IONENGINE_UTILITY_LOGGER_H

#include <IonEngine/extern/fmtlib.h>

#include <memory>
#include <string>

namespace IonEngine::Utility {

    class Logger
    {
    public:
        enum class SeverityLevel
        {
            None,
            Error,
            Warn,
            Info,
            Trace
        };

    public:
        SeverityLevel severityLevel = SeverityLevel::Trace;
    
    public:
        static void init();
        
        Logger(const std::string& name = "IonEngineLogger");
        ~Logger() = default;

        static Logger& getEngineLogger();
        static Logger& getClientLogger();
    
        template <typename... Args>
        void trace(const Args&... args)
        {
            if(SeverityLevel::Trace <= severityLevel) {
                print(fg(fmt::color::gray), args...);
            }
        }

        template <typename... Args>
        void info(const Args&... args)
        {
            if(SeverityLevel::Info <= severityLevel) {
                print(fg(fmt::color::green), args...);
            }
        }

        template <typename... Args>
        void warn(const Args&... args)
        {
            if(SeverityLevel::Warn <= severityLevel) {
                print(fg(fmt::color::yellow), args...);
            }
        }

        template <typename... Args>
        void error(const Args&... args)
        {
            if(SeverityLevel::Error <= severityLevel) {
                print(fg(fmt::color::red), args...);
            }
        }

    private:
        template <typename... Args>
        void print(const fmt::text_style& ts, const Args&... args)
        {
            auto time = Clock::getTime();
            std::string header = fmt::format("[{}][{:%H:%M:%S}]", m_name, time);
            std::string message = fmt::format(args...);
            std::string output = fmt::format("{} {}\n", header, message);
            fmt::print(ts, output);
        }

    private:
        std::string m_name;

    private:
        static std::unique_ptr<Logger> s_engineLogger;
        static std::unique_ptr<Logger> s_clientLogger;
    };

}

namespace IonEngine {

    using LogSeverityLevel = IonEngine::Utility::Logger::SeverityLevel;

}

#endif // IONENGINE_UTILITY_LOGGER_H

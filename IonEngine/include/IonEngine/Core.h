#ifndef IONENGINE_CORE_H
#define IONENGINE_CORE_H

#include <IonEngine/Utility.h>

#define ION_CORE_LOG_TRACE(...) do{ IonEngine::Utility::Logger::getEngineLogger().trace(__VA_ARGS__); } while(0)
#define ION_CORE_LOG_INFO(...)  do{ IonEngine::Utility::Logger::getEngineLogger().info( __VA_ARGS__); } while(0)
#define ION_CORE_LOG_WARN(...)  do{ IonEngine::Utility::Logger::getEngineLogger().warn( __VA_ARGS__); } while(0)
#define ION_CORE_LOG_ERROR(...) do{ IonEngine::Utility::Logger::getEngineLogger().error(__VA_ARGS__); } while(0)

#define ION_LOG_TRACE(...) do{ IonEngine::Utility::Logger::getClientLogger().trace(__VA_ARGS__); } while(0)
#define ION_LOG_INFO(...)  do{ IonEngine::Utility::Logger::getClientLogger().info( __VA_ARGS__); } while(0)
#define ION_LOG_WARN(...)  do{ IonEngine::Utility::Logger::getClientLogger().warn( __VA_ARGS__); } while(0)
#define ION_LOG_ERROR(...) do{ IonEngine::Utility::Logger::getClientLogger().error(__VA_ARGS__); } while(0)

#define ION_BIT(x) (1u << (x))

#define ION_EVALUATE__(...) __VA_ARGS__
#define ION_CORE_ASSERT(x, ...)                                                                                     \
    do {                                                                                                            \
        if(!(x)) {                                                                                                  \
            ION_CORE_LOG_ERROR("Assertion failed ({}): {}", #x, fmt::format(ION_EVALUATE__(__VA_ARGS__)));          \
            std::abort();                                                                                           \
        }                                                                                                           \
    } while(0)

#endif // IONENGINE_CORE_H

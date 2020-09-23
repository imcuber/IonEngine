#define IONENGINE_EVENTS_DEFINITIONS(type, categories)                  \
    EventType type##Event::getStaticType() noexcept                     \
    {                                                                   \
        return EventType::type;                                         \
    }                                                                   \
                                                                        \
    EventType type##Event::getType() const noexcept                     \
    {                                                                   \
        return type##Event::getStaticType();                            \
    }                                                                   \
                                                                        \
    const char* type##Event::getEventTypeString() const noexcept        \
    {                                                                   \
        return #type;                                                   \
    }                                                                   \
                                                                        \
    EventCategory type##Event::getCategory() const noexcept             \
    {                                                                   \
        return categories;                                              \
    }

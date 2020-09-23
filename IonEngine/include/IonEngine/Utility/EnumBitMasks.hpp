#ifndef IONENGINE_UTILITY_ENUMBITMASKS_HPP
#define IONENGINE_UTILITY_ENUMBITMASKS_HPP

#include <type_traits>

template<typename EnumType>
struct EnableBitMaskOperators
{
    static const bool enable = false;
};

#define ENABLE_BITMASK_OPERATORS(EnumType)              \
    template<>                                          \
    struct EnableBitMaskOperators<EnumType>             \
    {                                                   \
        static const bool enable = true;                \
    };

template<typename EnumType>
typename std::enable_if<EnableBitMaskOperators<EnumType>::enable, EnumType>::type
    operator~(EnumType rhs)
{
    static_assert(std::is_enum<EnumType>::value, "template parameter is not an enum type");

    using underlying = typename std::underlying_type<EnumType>::type;

    return static_cast<EnumType>(~static_cast<underlying>(rhs));
}

#define ENUM_BITMASK_BINARY_OPERATOR(op)                                                            \
    template<typename EnumType>                                                                     \
    typename std::enable_if<EnableBitMaskOperators<EnumType>::enable, EnumType>::type               \
        operator op(EnumType lhs, EnumType rhs)                                                     \
    {                                                                                               \
        static_assert(std::is_enum<EnumType>::value, "template parameter is not an enum type");     \
                                                                                                    \
        using underlying = typename std::underlying_type<EnumType>::type;                           \
                                                                                                    \
        return static_cast<EnumType>(static_cast<underlying>(lhs) op static_cast<underlying>(rhs)); \
    }

ENUM_BITMASK_BINARY_OPERATOR(| )
ENUM_BITMASK_BINARY_OPERATOR(&)
ENUM_BITMASK_BINARY_OPERATOR(^)

#undef ENUM_BITMASK_BINARY_OPERATOR

#define ENUM_BITMASK_MODIFYING_OPERATOR(op)                                                         \
    template<typename EnumType>                                                                     \
    typename std::enable_if<EnableBitMaskOperators<EnumType>::enable, EnumType>::type&              \
        operator op(EnumType& lhs, EnumType rhs)                                                    \
    {                                                                                               \
        static_assert(std::is_enum<EnumType>::value, "template parameter is not an enum type");     \
                                                                                                    \
        using underlying = typename std::underlying_type<EnumType>::type;                           \
                                                                                                    \
        lhs = static_cast<EnumType>(static_cast<underlying>(lhs) op static_cast<underlying>(rhs));  \
        return lhs;                                                                                 \
    }

ENUM_BITMASK_MODIFYING_OPERATOR(|=)
ENUM_BITMASK_MODIFYING_OPERATOR(&=)
ENUM_BITMASK_MODIFYING_OPERATOR(^=)

#undef ENUM_BITMASK_MODIFYING_OPERATOR

#endif // IONENGINE_UTILITY_ENUMBITMASKS_HPP

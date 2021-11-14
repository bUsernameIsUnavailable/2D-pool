#ifndef INC_2D_POOL_ECSTYPES_H
#define INC_2D_POOL_ECSTYPES_H

#include <bitset>
#include <cstdint>


namespace base {
    using Entity = std::uint32_t;
    static const Entity maxEntityCount = 10000u;

    using ComponentType = std::uint8_t;
    static const ComponentType maxComponentCount = 32u;

    using Signature = std::bitset<maxComponentCount>;
}


#endif //INC_2D_POOL_ECSTYPES_H

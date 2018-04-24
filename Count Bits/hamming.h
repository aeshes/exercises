#ifndef HAMMING_H
#define HAMMING_H

#include <cstddef>
#include <QDebug>

inline unsigned count(uint32_t n)
{
    unsigned bits = 0;
    while (n)
    {
        bits += n & 0x01 ? 1 : 0;
        n >>= 1;
    }
    return bits;
}

#endif // HAMMING_H

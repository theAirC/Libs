#pragma once

#define rounddiv(x,y)    ( ( ( ( (x) << 1 ) / (y) ) + 1 ) >> 1 )
#define upperdiv(x,y)      ( ( ( (x) -  1 ) / (y) ) + 1 )
#define roundmod(x,y)    ( x - (rounddiv(x,y) * y) )
#define uppermod(x,y)    ( x - (upperdiv(x,y) * y) )
//#define uppermod(x,y)      ( ( ( (x) -  1 ) % (y) ) + 1 - (y) )

namespace Math {

    size_t limit(size_t x, size_t min, size_t max)
    {
        if (x < min) return min;
        else if (x > max) return max;
        else return x;
    }

    bool isOdd(size_t x) { return (x & 1); }
    bool isEven(size_t x) { return !(x & 1); }

    size_t max(size_t a, size_t b) { return (a > b) ? a : b; }
    size_t min(size_t a, size_t b) { return (a < b) ? a : b; }

}

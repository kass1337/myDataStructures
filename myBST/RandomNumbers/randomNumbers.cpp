#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;
typedef unsigned long long INT_64;
class RandomInt {
    private:
        INT_64 RRand;
        const INT_64 mRand = (1 << 63)-1;
        const INT_64 aRand = 6364136223846793005;
        const INT_64 cRand = 1442695040888963407;
        void Srand() {
            srand(time(0)); RRand = (INT_64) rand();
        }
    public:
        RandomInt() {
            Srand();
            INT_64 y1, y2;
            y1 = (aRand * RRand + cRand) % mRand;
            y2 = (aRand * y1 + cRand) % mRand;
            RRand = y1 & 0xFFFFFFFF00000000LL ^ (y2 & 
            0xFFFFFFFF00000000LL) >> 32;
        }
        operator INT_64() {
            return RRand;
        }
};
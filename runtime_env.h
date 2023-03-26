#include <vector>
#include <array>

using AdrType = int;
using Wire = std::array<AdrType,2>;
using Wiring = std::vector<Wire>;

class CircuitGameV2 {
private:
    Wiring wiring;
    bool* stat;
    bool* newstat;
    AdrType size;
    bool* buffer1;
    bool* buffer2;
public:
    CircuitGameV2(Wiring);
    void next();
    bool get_stat(AdrType);
    void swap(bool*,bool*);
};
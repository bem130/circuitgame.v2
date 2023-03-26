#include <iostream>
#include "runtime_env.h"

CircuitGameV2::CircuitGameV2(Wiring wiring_) {
    wiring = {{0,0},{1,1}};
    wiring.insert(wiring.end(),wiring_.begin(),wiring_.end());
    size = wiring.size();
    buffer1 = new bool[size];
    buffer2 = new bool[size];
    for (AdrType i=0;i<size;i++) {
        buffer1[i] = 0;
    }
    stat = buffer1;
    newstat = buffer2;
}
void CircuitGameV2::next() {
    for (AdrType i=0;i<2;i++) {
        newstat[i] = i;
    }
    for (AdrType i=2;i<size;i++) {
        newstat[i] = !(get_stat(wiring[i][0])&&get_stat(wiring[i][1]));
    }
    bool* tmp = stat;
    stat = newstat;
    newstat = tmp;
}
bool CircuitGameV2::get_stat(AdrType adr) {
    if (adr>1) {return stat[adr];}
    else {return adr;}
}

int main() {
    Wiring test = {{0,0},{0,1},{1,0},{1,1},{5,5},{2,2}};
    CircuitGameV2 runtime(test);
    for (int a=0;a<10;a++) {
        runtime.next();
    }
}
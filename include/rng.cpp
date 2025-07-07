#include "rng.h"

std::mt19937& rng(){
    static std::mt19937 engine { std::random_device{}()};
    return engine;
}
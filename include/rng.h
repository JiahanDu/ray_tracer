#include <random>

#ifndef RNG_H
#define RNG_H

inline std::mt19937& rng(){
    static std::mt19937 rng(std::random_device{}());
    return rng;
}

inline std::uniform_real_distribution<double>& uniform_0_1_dist(){
    static std::uniform_real_distribution<double> dist(0, 1);
    return dist;
}

inline double random_0_1(){
    return uniform_0_1_dist()(rng()); // rng() is a static variable, so it will only be initialized once, and the same rng() will be used in the entire program
}

#endif
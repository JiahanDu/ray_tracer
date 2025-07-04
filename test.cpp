#include <iostream>
#include <chrono>
#include "Vector.h"  // your vector header

using namespace std::chrono;

int main() {
    constexpr int N = 10'000'000;

    Point p1(1.0, 2.0, 3.0);
    Point p2(4.0, 5.0, 6.0);
    Point p3;
    double d = 0.0;

    auto start = high_resolution_clock::now();

    // Benchmark operator+
    for (int i = 0; i < N; ++i) {
        p3 = p1 + p2;
    }

    auto mid1 = high_resolution_clock::now();

    // Benchmark operator*
    for (int i = 0; i < N; ++i) {
        p3 = p1 * 2.0;
    }

    auto mid2 = high_resolution_clock::now();

    // Benchmark dot product
    for (int i = 0; i < N; ++i) {
        d = dot(p1, p2);
    }

    auto mid3 = high_resolution_clock::now();

    // Benchmark cross product
    for (int i = 0; i < N; ++i) {
        p3 = cross(p1, p2);
    }

    auto end = high_resolution_clock::now();

    std::cout << "operator+ time: " 
              << duration_cast<milliseconds>(mid1 - start).count() << " ms\n";
    std::cout << "operator* time: " 
              << duration_cast<milliseconds>(mid2 - mid1).count() << " ms\n";
    std::cout << "dot product time: " 
              << duration_cast<milliseconds>(mid3 - mid2).count() << " ms\n";
    std::cout << "cross product time: " 
              << duration_cast<milliseconds>(end - mid3).count() << " ms\n";

    // Use results to avoid optimizing away
    std::cout << "Last dot result: " << d << "\n";
    std::cout << "Last cross result: " << p3 << "\n";

    return 0;
}

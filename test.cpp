#include <iostream>
#include <chrono>

// Non-inline function
int add_noninline(int a, int b) {
    return a + b;
}

// Inline function
inline int add_inline(int a, int b) {
    return a + b;
}

int main() {
    constexpr int iterations = 100'000'000;
    int result = 0;

    // Measure non-inline function time
    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        result += add_noninline(i, i);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_noninline = end - start;

    // Reset result
    result = 0;

    // Measure inline function time
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < iterations; ++i) {
        result += add_inline(i, i);
    }
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_inline = end - start;

    std::cout << "Non-inline function time: " << elapsed_noninline.count() << " seconds\n";
    std::cout << "Inline function time: " << elapsed_inline.count() << " seconds\n";

    return 0;
}

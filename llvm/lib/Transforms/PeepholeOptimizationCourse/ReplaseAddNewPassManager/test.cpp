#include <string>
#include <cstdlib>

int8_t sum_to_obfuscate(int8_t a, int8_t b, int8_t c, int8_t d) {
    return a + b + c + d;
}

int main(int argc, char* argv[]) {
    auto a = std::stoi(argv[1]);
    auto b = std::stoi(argv[2]);
    auto c = std::stoi(argv[3]);
    auto d = std::stoi(argv[4]);
    return sum_to_obfuscate(a, b, c, d);
}

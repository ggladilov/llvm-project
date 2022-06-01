#include <string>
#include <cstdlib>

int8_t sum_to_obfuscate(int8_t a, int8_t b) {
    return a + b;
}

int main(int argc, char* argv[]) {
    auto a = std::stoi(argv[1]);
    auto b = std::stoi(argv[2]);
    int8_t res = sum_to_obfuscate(a, b);
	return res;
}
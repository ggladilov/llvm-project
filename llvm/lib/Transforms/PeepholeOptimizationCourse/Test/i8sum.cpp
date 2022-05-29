#include <string>

int main(int argc, char *argv[]) {
    int8_t a = std::stoi(argv[1]);
    int8_t b = std::stoi(argv[2]);
    int8_t sum = a + b;
    return sum;
}

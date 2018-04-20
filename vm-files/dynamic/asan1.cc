// clang++ -std=c++11 asan1.cc -fsanitize=address
#include <iostream>

constexpr char hello[]{"Hello"};
constexpr char world[]{"world"};

char *copy_hello(char *out) {
    for (auto c : hello)
        if (c != '\0')
            *out++ = c;
    return out;
}

char *copy_world(char *out) {
    for (auto c : world)
        *out++ = c;
    return out;
}

int main(void) {
    // buffer for "Hello", "world" (11 chars with space between)
    char buf[10 + 1];
    char *ptr;
    
    ptr = copy_hello(buf);
    *ptr++ = ' ';
    copy_world(ptr);
    
    std::cout << std::string(buf) << std::endl;
}

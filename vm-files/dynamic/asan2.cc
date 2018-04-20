// clang++ -std=c++17 asan1.cc -fsanitize=address
#include <iostream>

int main(void) {
    std::string hello = "Helloooooooooooooooooooooooooooooooo ";
    std::string_view view = hello + "world!";
    
    std::cout << view << std::endl;
    
    
    std::string s = "Hello ";
    std::string_view sv = s + "world!";
    
    std::cout << sv << std::endl;
}

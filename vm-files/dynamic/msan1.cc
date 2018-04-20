// clang++ -std=c++11 msan1.cc -fsanitize=memory
// all the used code has to be build with msan! (stdlib, all dependencies...)

int main(void) {
    int x;
    if (x)
        return 0;
    return 1;
}

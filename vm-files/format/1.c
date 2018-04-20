// clang-format 1.c
// also: https://hero.handmade.network/forums/code-discussion/t/1563-clang-format_for_formatting_c_c++_code

void sum(int a, int b, int c,
#if LONG
    long d,
    int e) {
#else
    int d,
    int e) {
#endif
  return a + b + c + d + e;
}

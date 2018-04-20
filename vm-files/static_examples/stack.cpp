char const *p;

void test1() {
  char const str[] = "string";
  p = str; // warn
}
void* test2() {
   return __builtin_alloca(12); // warn
}
void test3() {
  static int *x;
  int y;
  x = &y; // warn
}

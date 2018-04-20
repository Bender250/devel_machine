void test() {
  int x;
  x |= 1; // warn: left expression is unitialized
}

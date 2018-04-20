void test1(int z) {
  if (z == 0)
    int x = 1 / z; // warn
}
void test2() {
  int x = 1;
  int y = x % 0; // warn
}

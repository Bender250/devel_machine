void test() {
  int x;
  ^{ int y = x; }(); // warn
}

void test1() {
  int x;
  int vla1[x]; // warn: garbage as size
}
void test2() {
  int x = 0;
  int vla2[x]; // warn: zero size
}

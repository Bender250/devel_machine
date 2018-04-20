// C
void test1(int *p) {
  if (p)
    return;

  int x = p[0]; // warn
}
// C
void test2(int *p) {
  if (!p)
    *p = 0; // warn
}
// C++
class C {
public:
  int x;
};

void test3() {
  C *pc = 0;
  int k = pc->x; // warn
}

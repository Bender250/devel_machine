// C
struct S {
  int x;
};

void f(struct S s);

void test1() {
  struct S s;
  f(s); // warn: passed-by-value arg contain uninitialized data
}
// C
void test2() {
  void (*foo)(void);
  foo(); // warn: function pointer is uninitialized
}
// C
void test3() {
  void (*foo)(void);
  foo = 0;
  foo(); // warn: function pointer is null
}
// C++
class C1 {
public:
  void f();
};

void test4() {
  C1 *pc;
  pc->f(); // warn: object pointer is uninitialized
}
// C++
class C2 {
public:
  void f();
};

void test5() {
  C2 *pc = 0;
  pc->f(); // warn: object pointer is null
}

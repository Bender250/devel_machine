// clang-tidy -checks='-*,modernize-use-override' tidy/2.cc -- -std=c++11
// https://github.com/Microsoft/clang-tools-extra/blob/master/test/clang-tidy/modernize-use-override.cpp

struct Base {
  virtual ~Base() {}
  virtual void a();
  virtual void b();
  virtual void c();
  virtual void d();
  virtual void d2();
  virtual void e() = 0;
  virtual void f() = 0;
  virtual void f2() const = 0;
};

struct SimpleCases : public Base {
public:
  virtual ~SimpleCases();

  void a();
  void b() override;
  virtual void c();
  virtual void d() override;
  virtual void d2() final;
  virtual void e() = 0;
  virtual void f()=0;
  virtual void f2() const=0;
};

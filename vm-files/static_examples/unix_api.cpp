// unix.API
// Currently the check is performed for apple targets only.
void test(const char *path) {
  int fd = open(path, O_CREAT);
    // warn: call to 'open' requires a third argument when the
    // 'O_CREAT' flag is set
}
void f();

void test() {
  pthread_once_t pred = {0x30B1BCBA, {0}};
  pthread_once(&pred, f);
    // warn: call to 'pthread_once' uses the local variable
}
void test() {
  void *p = malloc(0); // warn: allocation size of 0 bytes
}
void test() {
  void *p = calloc(0, 42); // warn: allocation size of 0 bytes
}
void test() {
  void *p = malloc(1);
  p = realloc(p, 0); // warn: allocation size of 0 bytes
}
void test() {
  void *p = alloca(0); // warn: allocation size of 0 bytes
}
void test() {
  void *p = valloc(0); // warn: allocation size of 0 bytes
}

// unix.Malloc
void test() {
  int *p = malloc(1);
  free(p);
  free(p); // warn: attempt to free released memory
}
void test() {
  int *p = malloc(sizeof(int));
  free(p);
  *p = 1; // warn: use after free
}
void test() {
  int *p = malloc(1);
  if (p)
    return; // warn: memory is never released
}
void test() {
  int a[] = { 1 };
  free(a); // warn: argument is not allocated by malloc
}
void test() {
  int *p = malloc(sizeof(char));
  p = p - 1;
  free(p); // warn: argument to free() is offset by -4 bytes
}

// unix.MallocSizeof
void test() {
  long *p = malloc(sizeof(short));
    // warn: result is converted to 'long *', which is
    // incompatible with operand type 'short'
  free(p);
}

// unix.MismatchedDeallocator
// C, C++
void test() {
  int *p = (int *)malloc(sizeof(int));
  delete p; // warn
}
// C, C++
void __attribute((ownership_returns(malloc))) *user_malloc(size_t);

void test() {
  int *p = (int *)user_malloc(sizeof(int));
  delete p; // warn
}
// C, C++
void test() {
  int *p = new int;
  free(p); // warn
}
// C, C++
void test() {
  int *p = new int[1];
  realloc(p, sizeof(long)); // warn
}
// C, C++
template <typename T>
struct SimpleSmartPointer {
  T *ptr;

  explicit SimpleSmartPointer(T *p = 0) : ptr(p) {}
  ~SimpleSmartPointer() {
    delete ptr; // warn
  }
};

void test() {
  SimpleSmartPointer<int> a((int *)malloc(4));
}
// C++
void test() {
  int *p = (int *)operator new(0);
  delete[] p; // warn
}
// Objective-C, C++
void test(NSUInteger dataLength) {
  int *p = new int;
  NSData *d = [NSData dataWithBytesNoCopy:p
               length:sizeof(int) freeWhenDone:1];
    // warn +dataWithBytesNoCopy:length:freeWhenDone: cannot take
    // ownership of memory allocated by 'new'
}

// unix.Vfork
int test(int x) {
  pid_t pid = vfork(); // warn
  if (pid != 0)
    return 0;

  switch (x) {
  case 0:
    pid = 1;
    execl("", "", 0);
    _exit(1);
    break;
  case 1:
    x = 0; // warn: this assignment is prohibited
    break;
  case 2:
    foo(); // warn: this function call is prohibited
    break;
  default:
    return 0; // warn: return is prohibited
  }

  while(1);
}

// unix.cstring.BadSizeArg
void test() {
  char dest[3];
  strncat(dest, "***", sizeof(dest));
    // warn: potential buffer overflow
}

// unix.cstring.NullArg
int test() {
  return strlen(0); // warn
}

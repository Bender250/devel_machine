void test() {
  char *x = mktemp("/tmp/zxcv"); // warn: insecure, use mkstemp
}

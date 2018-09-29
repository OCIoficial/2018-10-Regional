#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  inf.readInt(1, 50, "M");
  inf.readEoln();
  inf.readEof();
  return 0;
}

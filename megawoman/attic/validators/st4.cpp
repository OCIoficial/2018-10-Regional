#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  long N = inf.readLong(1LL, 1000000000000LL, "N");
  inf.readEoln();

  inf.readLong(0, N-1, "w");
  inf.readSpace();
  inf.readLong(1, 1000000000, "v");
  inf.readEoln();

  int R = inf.readInt(1, 100000, "R");
  inf.readEoln();
  for (int i = 0; i < R; ++i) {
    inf.readLong(0, N-1, "r");
    inf.readSpace();
    long v = inf.readLong(-1000000000, 1000000000, "v");
    ensuref(v != 0, "Velocidad de los robots no puede ser cero.");
    inf.readEoln();
  }
  inf.readEof();
}

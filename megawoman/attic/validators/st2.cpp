#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(1, 100000, "N");
  inf.readEoln();

  inf.readInt(0, N-1, "w");
  inf.readSpace();
  inf.readInt(1, 1, "v");
  inf.readEoln();

  int R = inf.readInt(1, 100000, "R");
  inf.readEoln();
  for (int i = 0; i < R; ++i) {
    inf.readInt(0, N-1, "r");
    inf.readSpace();
    inf.readInt(-1, -1);
    inf.readEoln();
  }
  inf.readEof();
}

#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int N = inf.readInt(1, 48, "N");
  inf.readEoln();

  int sum = 0;

  for (int i = 0; i < N; i++) {
   sum += inf.readInt(1, 100, "A_i");
   inf.readEoln();
  }
  
  ensuref(sum <= 48, "Problema debe tener solución.");
  inf.readEof();
  return 0;
}

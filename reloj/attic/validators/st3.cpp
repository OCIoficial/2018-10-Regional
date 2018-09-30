/*
 * -----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <nlehmann@dcc.uchile.cl> wrote this file. As long as you retain this notice
 * you can do whatever you want with this stuff. If we meet some day, and you
 * think this stuff is worth it, you can buy me a beer in return Nicolás Lehmann
 * -----------------------------------------------------------------------------
 */

#include "testlib.h"

using namespace std;

int main() {
  registerValidation();
  int M = inf.readInt(1, 100000, "M");
  inf.readSpace();
  int N = inf.readInt(1, 1000000, "N");
  inf.readEoln();

  long long sum = 0LL;

  for (int i = 1; i < N; i++) {
    sum += inf.readInt(0, 100, "m");
    inf.readSpace();
  }

  sum += inf.readInt(0, 100, "m");
  inf.readEoln();

  ensuref(sum >= M, "Problema debe tener solución.");

  inf.readEof();
  return 0;
}

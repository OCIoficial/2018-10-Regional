#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool check(const vector<long> &vec, long total) {
  long sum = 0;
  for (uint i = 0; i < vec.size(); ++i) {
    sum += vec[i];
  }
  return sum == total;
}

long count(const string &s, vector<long> &vec, int n, uint i) {
  if (n == 0) {
    if (s.size() - i > 9)
      return 0;
    return check(vec, stoi(s.substr(i)));
  }
  long sum = 0;
  for (uint j = 1; j <= min(9u, int(s.size()) - i - 1); ++j) {
    vec.push_back(stoi(s.substr(i, j)));
    sum += count(s, vec, n - 1, i + j);
    vec.pop_back();
  }
  return sum;
}

int main() {
  registerValidation();
  string s;
  inf.readLineTo(s);
  ensuref(s.size() <= 28, "Cadena debe tener largo menor o igual que 28");
  for (char c : s)
    ensuref('1' <= c and c <= '9', "La cadena debe contener solo digitos excluyedo el cero");
  long sum = 0;
  for (uint i = 1; i <= 2; ++i) {
    int n = stoi(s.substr(0, i));
    vector<long> vec;
    sum += count(s, vec, n, i);
  }
  ensuref(sum == 1, "Debe haber una solución única.");
  inf.readEof();
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

bool check(const vector<long> &vec) {
  long sum = 0;
  for (uint i = 0; i < vec.size() - 1; ++i) {
    sum += vec[i];
  }
  return sum == vec[vec.size() - 1];
}

bool sol(const string &s, vector<long> &vec, int n, uint i) {
  if (n == 0) {
    if (s.size() - i > 9)
      return false;
    vec.push_back(stoi(s.substr(i)));
    if (check(vec))
      return true;
    vec.pop_back();
    return false;
  }
  for (uint j = 1; j <= min(9u, int(s.size()) - i - 1); ++j) {
    vec.push_back(stoi(s.substr(i, j)));
    if (sol(s, vec, n - 1, i + j))
      return true;
    vec.pop_back();
  }
  return false;
}

int main() {
  string s;
  cin >> s;
  for (uint i = 1; i <= 2; ++i) {
    int n = stoi(s.substr(0, i));
    vector<long> vec;
    if (sol(s, vec, n, i)) {
      cout << n;
      for (uint j = 0; j < vec.size(); ++j) {
        cout << " " << vec[j];
      }
      cout << "\n";
      break;
    }
  }
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
  int M, N;
  cin >> M >> N;

  vector<int> accum(N+1);
  for (int i = 0; i < N; ++i) {
    int v;
    cin >> v;
    accum[i + 1] = accum[i] + v;
  }

  int res = INT_MAX;
  for (int i = 0; i < N; ++i) {
    int l = i, r = N;
    while (l < r) {
      int m = l + (r - l)/2;
      int val = accum[m+1] - accum[i];
      if (val >= M) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    if (l >= N) {
      break;
    }
    res = min(res, l - i + 1);
  }
  cout << res << "\n";
  return 0;
}

#include <iostream>
using namespace std;

long N, w, v, R;

int main () {
  cin >> N;
  cin >> w >> v;
  cin >> R;

  for (int i = 0; i < R; ++i) {
    long r, u;
    cin >> r >> u;
    // w + v*t = r + u*t
    // t = (r - w)/(v - u)
    int a = r - w;
    int b = v - u;
    if (a == 0) {
      cout << "NO\n";
      return 0;
    }
    if (b !=0 && a % b == 0 && a/b > 0 && w+v*a/b < N) {
      cout << "NO\n";
      return 0;
    }
  }
  cout << "SI\n";
  return 0;
}

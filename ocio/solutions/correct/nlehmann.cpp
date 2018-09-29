#include <iostream>
#include <vector>
using namespace std;
int main() {
  int M;
  cin >> M;

  int i = 1;
  vector<int> prev = {1};
  int total_length = 2;
  while(true) {
    vector<int> curr = {};
    int  run_length = 1;
    uint j;
    for (j = 1; j < prev.size(); ++j) {
      if(prev[j] != prev[j-1]) {
        curr.push_back(run_length);
        curr.push_back(prev[j-1]);
        run_length = 1;
      } else {
        run_length += 1;
      }
    }
    curr.push_back(run_length);
    curr.push_back(prev[j-1]);
    if(total_length + curr.size() > M) {
      cout << i << "\n";
      break;
    }
    total_length += curr.size() + 1;
    swap(prev, curr);
    i += 1;
   }
}

#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a; i<=b; ++i)
typedef long long int ll;

int n;
int digits[50];
const ll LIMIT = (ll)1e9;

ll get_num(int i, int j) {
    ll x = 0;
    rep(k,i,j) x = x * 10 + digits[k];
    return x;
}

int num_digits(ll x) {
    int c = 1; ll pt = 10;
    while (pt <= x) { c++; pt *= 10; }
    return c;
}

stack<ll> answer;

bool solve(int k, int i, ll acc, int nd) {
    if (k == 0) {
        if (nd != n - i) return false;
        if (get_num(i, n-1) != acc) return false;
        answer.push(acc);
        return true;
    }
    if (n - i - k < nd) return false;
    int maxj = min(n-k-nd, i+8);
    rep(j, i, maxj) {
        ll num = get_num(i,j);
        ll tmp = acc + num;
        if (tmp >= LIMIT) break;
        if (solve(k-1, j+1, tmp, num_digits(tmp))) {
            answer.push(num);
            return true;
        }
    }
    return false;    
}

int main() {
    string line; cin >> line;

    clock_t begin = clock();
    n = line.size();
    rep(i,0,n-1) digits[i] = line[i] - '0';
    rep(i,0,1) {
        int k = get_num(0,i);
        if (solve(k,i+1,0,1)) {
            answer.push(k);
            break;
        }
    }
    assert (answer.size() > 0);
    while (!answer.empty()) {
        ll num = answer.top(); answer.pop();
        cout << num;
        if (!answer.empty()) cout << " ";
    }
    cout << endl;

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "elapsed secs: " << elapsed_secs << end;
    return 0;
}
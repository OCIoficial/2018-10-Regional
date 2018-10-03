#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    long long nc, w, ran, v, nr, r, u;

    cin >> nc >> w >> v >> nr;

    ran = (nc - w + v - 1LL) / v;

    bool possible = true;

    for(int i = 0; i < nr; i++) {
        cin >> r >> u;

        if (v == u) {
            if (r == w) {
                possible = false;
                break;
            }
        }
        else {
            long long t = (r - w) / (v - u);
            if ((r - w) % (v - u) == 0LL && 0LL <= t && t < ran) {
                possible = false;
                break;
            }
        }
    }

    cout << (possible ? "SI" : "NO") << endl;

    return 0;
}

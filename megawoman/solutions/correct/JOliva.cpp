#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long N, w, v, R;
    cin >> N >> w >> v >> R;

    for (int i=0;i<R;i++){
        long long wi, vi;
        cin >> wi >> vi;
        long long V=v-vi;
        long long W=wi-w;
        long long tfinal=(N-w+V-1)/v;
        if (V==0){
            if (W==0){
                cout << "NO\n";return 0;
            }
        }
        else if (W%V==0){
            long long t=W/V;
            if (t>=0 and t<tfinal){
                cout << "NO\n";return 0;
            }
        }
    }
    cout << "SI\n";
    return 0;
}

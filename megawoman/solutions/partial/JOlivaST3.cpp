#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    long long N, w, v, R;
    cin >> N >> w >> v >> R;
    long long tfinal=(N-w+v-1)/v;
    for (int i=0;i<R;i++){
        long long wi, vi;
        cin >> wi >> vi;
        for (long long int s=0;s<tfinal;s++){
            if (vi<0 and w+s*v>wi+s*vi){
                break;
            }
            if (vi>0 and v-vi<0 and w+s*v<wi+s*vi)
                break;
            if (vi>0 and v-vi>0 and w+s*v>wi+s*vi)
                break;
            if (w+s*v==wi+s*vi){
                cout << "NO\n";return 0;
            }
        }
    }
    cout << "SI\n";
    return 0;
}

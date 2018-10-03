#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M;
    cin >> M >> N;
    vector<int>metros(N+1, 0);

    for (int i=1;i<=N;i++){
        cin >> metros[i];
    }
    int j=0;
    int suma=0;
    int best=INT_MAX;
    for (int i=0;i<=N;i++){
        for (;j<=N and suma<M;j++){
            suma+=metros[j];
        }
        if (suma>=M){
            best=min(best, j-i);
        }
        suma-=metros[i];
    }
    cout << best << "\n";
    return 0;
}

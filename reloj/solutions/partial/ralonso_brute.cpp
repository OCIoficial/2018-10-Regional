#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int m, n, sum, best;

    cin >> m >> n;

    best = n;

    vector < int > samples(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> samples[i];
    }

    // Para cada intervalo...
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            // Calculamos los metros recorridos
            sum = 0;

            for(int k = i; k < j; k++) {
                sum += samples[k];
            }

            // Si son al menos "m" y no hemos encontrado un mejor tiempo, guardar
            if(sum >= m && j - i < best) {
                best = j - i;
            }
        }
    }

    cout << best << endl;

    return 0;
}

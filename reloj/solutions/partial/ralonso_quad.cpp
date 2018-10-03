#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int m, n, t, sum;

    cin >> m >> n;

    vector < int > samples(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> samples[i];
    }

    // Buscar de menor a mayor el intervalo válido óptimo
    for(t = 1; t <= n; t++) {
        sum = 0;

        // Partimos en cero y vemos la distancia recorrida en t segundos
        for(int i = 0; i < t; i++) {
            sum += samples[i];
        }

        for(int i = 0; i + t < n; i++) {
            if(sum >= m) {
                break; // Encontramos el intervalo válido óptimo
            }

            // Movemos el intervalo a la derecha
            sum -= samples[i];
            sum += samples[i + t];
        }
        if(sum >= m) {
            break; // Encontramos el intervalo válido óptimo
        }
    }

    cout << t << endl;

    return 0;
}

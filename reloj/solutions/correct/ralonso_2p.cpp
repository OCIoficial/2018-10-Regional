#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int m, n, best;

    cin >> m >> n;

    best = n;

    vector < int > samples(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> samples[i];
    }

    // Usamos dos punteros y mantenemos la suma de lo que hay al medio
    int i = 0, j = 0, sum = 0;

    while(j < n) {
        // La suma es menor que m, así que avanzamos el puntero derecho
        sum += samples[j++];

        // Si la suma es mayor o igual que m, estamos en el intervalo valido que parte de i
        while(sum >= m) {
            // Revisamos si es el mejor intervalo válido
            if(j - i < best) {
                best = j - i;
            }

            // Avanzamos i
            sum -= samples[i++];
        }
    }

    cout << best << endl;

    return 0;
}

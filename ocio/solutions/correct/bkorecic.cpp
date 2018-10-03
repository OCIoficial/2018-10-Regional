#include <bits/stdc++.h>
using namespace std;

string siguiente_numero(string a){
	string ans = "";
	char actual = a[0];
	int contador = 1;
	int len = a.length();
	for(int i=1; i<len; i++){
		if(a[i] == actual){
			contador++;
		}
		else{
			ans += to_string(contador) + actual;
			actual = a[i];
			contador = 1;
		}
	}
	ans += to_string(contador) + actual;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int M; cin >> M;
	string actual = "1"; // "1" es el string inicial
	actual = siguiente_numero(actual); //primera iteración (siempre se hace, M>0)
	int m_acumulada = 1, ans = 1, len = 2; //len es el tamaño del string actual
	while(m_acumulada + len + 1<= M){ //mientras quepa un número más, se repite el ciclo
		ans++;
		m_acumulada += len + 1; // +1 por el espacio
		actual = siguiente_numero(actual);
		len = actual.length();
	}
	cout << ans << '\n';
	return 0;
}

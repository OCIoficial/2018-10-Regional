#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int M;
	cin >> M;
	if(M<=3){
		cout << "1" << endl;
	}
	else if(M<=6){
		cout << "2" << endl;
	}
	else if(M<=11){
		cout << "3" << endl;
	}
	else if(M<=18){
		cout << "4" << endl;
	}
	else if(M<=25){
		cout << "5" << endl;
	}
	else if(M<=34){
		cout << "6" << endl;
	}
	else if(M<=45){
		cout << "7" << endl;
	}
	else{
		cout << "8" << endl;
	}
	return 0;
}

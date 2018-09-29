#include <iostream>
using namespace std;

int main() {
	int n, g = 0, s = 0;
	cin >> n;

	for(int i=0;i<n;i++)
	{
	    cin >> s;
	    if((s%2==1)&&(s>1))
	    	g++;
	}
	cout << g << "\n";
	return 0;
}

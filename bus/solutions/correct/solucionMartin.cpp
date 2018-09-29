#include<bits/stdc++.h>
using namespace std;
int main(){

int n,a=0,contador=0,b;
cin>>n;

while(a<n){
	      
	      cin>>b;
	      if(b%2!=0 and b!=1){contador++;}
	      a++;
          }
cout<<contador << "\n";

return 0;            
}

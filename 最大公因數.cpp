#include<iostream>
using namespace std;
int gcd(int a, int b){
  if (b == 0){
    return a;
  }
  else
    return gcd(b, a % b);
}
int main(){
	int a,b,c;
	while(cin>>a>>b){
		if (a<b){
			c = b;
			b = a;
			a = c;
		}
		cout<<gcd(a,b)<<endl;
	}
}

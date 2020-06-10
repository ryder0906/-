#include<iostream>
using namespace std;
int F(int x){
	if (x == 0){
		return 1;
	}
	else if(x==1){
		return 1;
	}
	else{
		return F(x-1)+F(x-2);
	}
}
int main(){
	int n;
	while(cin >> n){
		cout << F(n) << endl;
	}
}

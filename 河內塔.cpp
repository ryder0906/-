#include<iostream>
using namespace std;
void F(int a,char A,char B,char C){
	if(a==1){
		cout<<"Move ring "<<a<<" from "<<A<<" to "<<C<<endl;
	}
	else{
		F(a-1,A,C,B);
		cout<<"Move ring "<<a<<" from "<<A<<" to "<<C<<endl;
		F(a-1,B,A,C);
	}
}
int main(){
	int k;
	char a='A',b='B',c='C';
	while(cin>>k){
		F(k,a,b,c);		
	}
}

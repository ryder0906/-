#include<iostream>
using namespace std;

int H(int k,char a,char b,char c){
	int ans = 0;
	if(k==0){
		return 0;
	}
	if(k==1){
		cout<<"ring "<<k<<" : "<<a<<" -> "<<c<<endl;
		ans++;
		return ans;
	}
	else{
		ans += H(k-1,a,c,b);
		cout<<"ring "<<k<<" : "<<a<<" -> "<<c<<endl;
		ans ++;
		ans += H(k-1,b,a,c);
		return ans;
	}
}
int F(int k,char a,char b,char c){
	int steps=0;
	if(k==0){
		return 0;
	}
	if(k==1){
		cout<<"ring "<<k<<" : "<<a<<" -> "<<c<<endl;
		steps++;
		return steps;		
	}
	if(k==2){
		cout<<"ring "<<k-1<<" : "<<a<<" -> "<<b<<endl;
		steps++;
		cout<<"ring "<< k <<" : "<<a<<" -> "<<c<<endl;
		steps++;
		return steps;
	} 
	else{
		steps += H(k-1,a,c,b);
		cout<<"ring "<<k<<" : "<<a<<" -> "<<c<<endl;
		steps ++;
		steps += H(k-3,b,c,a);
		cout<<"ring "<< k-2 <<" : "<<b<<" -> "<<c<<endl;
		steps ++;
		steps += F(k-3,a,c,b);
		return steps;
	}
}
int main(){
	int u,steps;
	while(cin>>u){
		if (u%2==0){
			steps = F(u,'a','b','c');
			cout<<"共移動了 "<<steps<<" 步"<<endl;
		}
 		else{
			steps = F(u,'a','c','b');
			cout<<"共移動了 "<<steps<<" 步"<<endl;			
		}
	} 
}

#include <iostream>
#include <vector>
using namespace std;
int main(){
	int a,b;
	cin >> a;
	//將數字存進vector中 
	vector<int> v;
	for (int i = 0;i < a; i++){
		cin>>b;
		v.push_back(b);
	}
	//氣泡排序 
	for(int j = v.size()-1 ; j>0;j--){
		for(int k = 0 ; k<(a-1) ; k ++){
			if(v[k]>v[k+1]){
				int temp;
				temp = v[k+1];
				v[k+1] = v[k];
				v[k] = temp;
			}
		}
	}
	//印出結果 
	for(int l=0;l<a;l++){
		cout<<v[l]<<" ";
	}
} 

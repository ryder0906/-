#include <iostream>
#include <vector>
using namespace std;
int main(){
	int a,b;
	cin >> a;
	//�N�Ʀr�s�ivector�� 
	vector<int> v;
	for (int i = 0;i < a; i++){
		cin>>b;
		v.push_back(b);
	}
	//��w�Ƨ� 
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
	//�L�X���G 
	for(int l=0;l<a;l++){
		cout<<v[l]<<" ";
	}
} 

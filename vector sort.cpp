#include <iostream>
#include <vector>
#include <algorithm>
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
	//�Ƨ� 
	sort(v.begin(), v.end());
	//�L�X���G 
	for(int l=0;l<a;l++){
		cout<<v[l]<<" ";
	} 
}

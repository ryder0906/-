#include <iostream>
#include <vector>
#include <algorithm>
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
	//排序 
	sort(v.begin(), v.end());
	//印出結果 
	for(int l=0;l<a;l++){
		cout<<v[l]<<" ";
	} 
}

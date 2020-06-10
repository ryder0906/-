#include <iostream>
#include <cstdlib>
using namespace std;

int compare(const void * a,const void * b){
	return (*(int*)a - *(int*)b);
}
int main(){
	int n;
	while(cin >> n){
	//將數字存入陣列中 
		int arr[n];
		for(int i = 0; i<n ; i++){
			cin>>arr[i];
		}
		//qsort 
		qsort(arr,n,sizeof(int),compare);
		//印出結果 
		for(int j = 0; j<n ; j++){
			cout<<arr[j]<<" ";
		}		
	}
	
}
 

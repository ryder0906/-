#include<iostream>
#include<string>
using namespace std;
string pluss(string e,string f){
	int arr1[500]={0},arr2[500]={0},total[500]={0};

	for(int i=499 ; i>=500-(e.length()) ; i--){
		arr1[i]=(e[e.length()-(500-i)]-'0');
	}
	for(int j=499 ; j>=500-(f.length()) ; j--){
		arr2[j]=(f[f.length()-(500-j)]-'0');
	}
	for(int k=499 ; k>=0 ; k--){
		if (total[k]+arr1[k]+arr2[k]>=10){
			total[k]=total[k]+arr1[k]+arr2[k]-10;
			total[k-1]+=1;
		}
		else{
			total[k]=total[k]+arr1[k]+arr2[k];
		}
	}
	string ans="";
	int p;
	int count = 0;
	for(int r=0 ; r<=499 ; r++){
		if(total[r]!=0){
			p=r;
			break;
		}
		if(total[r]==0){
			count+=1;
		}
	}
	if(count==500){
		p=499;
	}
	for(int l=p ; l<=499 ; l++){
		ans += total[l]+'0';
	}
	return ans;
}
string minuss(string e,string f){
	int arr1[500]={0},arr2[500]={0},total[500]={0};	
	for(int i=499 ; i>=500-(e.length()) ; i--){
		arr1[i]=(e[e.length()-(500-i)]-'0');
	}
	for(int j=499 ; j>=500-(f.length()) ; j--){
		arr2[j]=(f[f.length()-(500-j)]-'0');
	}
	for(int k=499;k>(499-e.length());k--){
		total[k]=arr1[k]-arr2[k];
	}
	for(int l=499;l>(499-e.length());l--){
		if (total[l]<0){
			total[l-1] -= 1;
			total[l] += 10;
		}
	}
	string ans="";
	int p;
	int count = 0;
	for(int r=0 ; r<=499 ; r++){
		if(total[r]!=0){
			p=r;
			break;
		}
		if(total[r]==0){
			count+=1;
		}
	}
	if(count==500){
		p=499;
	}
	for(int m=p ; m<=499 ; m++){
		ans += total[m]+'0';
	}
	return ans;
}
bool cmp(string a,string b){
	if (a.length()<b.length()){
		return false;
	}
	else if (a.length()>b.length()){
		return true;
	}
	else{
		for(int i=0;i<(a.length());i++){
			if ((a[i]-'0')>(b[i]-'0')){
				return true;
			}
			if ((a[i]-'0')<(b[i]-'0')){
				return false;
			}
		}
	}
	return false;
}
string times(string e,string f){
	int arr1[500]={0},arr2[500]={0},total[500]={0},calculate[500]={0},mod[500]={0};
	int t = 499,h = 499;
	for(int i=499 ; i>=500-(e.length()) ; i--){
		arr1[i]=(e[e.length()-(500-i)]-'0');
	}
	for(int j=499 ; j>=500-(f.length()) ; j--){
		arr2[j]=(f[f.length()-(500-j)]-'0');
	}
	if(!cmp(e,f)){
		for(int k=499;k>=(500-f.length());k--){
			t=k;
			for(int m=499;m>=(500-e.length());m--){
				calculate[t]+=((arr2[k])*(arr1[m])%10);
				mod[t-1]+=((arr2[k])*(arr1[m])/10);
				t-=1;			
			}			
		}
	}
	else{
		for(int q=499;q>=(500-e.length());q--){
			h=q;
			for(int r=499;r>=(500-f.length());r--){
				calculate[h]+=((arr1[q])*(arr2[r])%10);
				mod[h-1]+=((arr1[q])*(arr2[r])/10);
				h-=1;			
			}
		}		
	}
	int check;
	for(int n=499;n>=0;n--){
		if(total[n]+calculate[n]+mod[n]>=10){
			check=total[n]+calculate[n]+mod[n];
			total[n]=total[n]+calculate[n]+mod[n]-10*(check/10);
			total[n-1]+=(check/10);
		}
		else{
			total[n]=total[n]+calculate[n]+mod[n];
		}
	}
	
	string ans="";
	int p;
	int count = 0;
	for(int r=0 ; r<=499 ; r++){
		if(total[r]!=0){
			p=r;
			break;
		}
		if(total[r]==0){
			count+=1;
		}
	}
	if(count==500){
		p=499;
	}
	for(int c=p ; c<=499 ; c++){
		ans += total[c]+'0';
	}
	return ans; 
}	
string dividess(string e,string f){
	string ans="";
	string check;
	if(cmp(e,f)){
		int z = e.length()-f.length();
		for(z;z>=0;z--){
			for(int a=1;a<=10;a++){
				check = times((f+string(z,'0')),string(1,(a+'0')));
				//cout<<check<<endl;

				if(cmp(check,e)){
					a = a-1;
					ans = ans + string(1,(a+'0'));
					e = minuss(e,times((f+string(z,'0')),string(1,(a+'0'))));
				//	cout << e <<endl;
					break;
				}
			}
		}
		
	}
	while(ans[0]=='0'){
		ans.erase(0,1);
	}
	return ans;	
}



int main(){
	char c;
	string a,b;
	while(cin>>a>>c>>b){	
		switch(c){
			case '+':
				cout<<pluss(a,b)<<endl;
				break;
			case '-':
				if(a==b){
					cout<<0<<endl;
					break;
				}
				else if(cmp(a,b)){
					cout<<minuss(a,b)<<endl;
					break;
				}
				else{
					cout<<"-"+minuss(b,a)<<endl;
					break;
				}
			case '*':
				cout<<times(a,b)<<endl;
				break;
			case '/':
				if(cmp(b,a)){
					cout<<0<<endl;
					break;
				}
				if(a==b){
					cout<<1<<endl;
					break;
				}
				else{
					cout<<dividess(a,b)<<endl;
					break;
				}				
		}
	}
}


#include<iostream>
#include<string>
#include<vector> 
using namespace std;
class account{
	public:
		string id;
		string password;
		int balance;
		account(){balance=0;}
};
int finduser(vector<account> user,string id){
	for(int i=0;i<user.size();i++){
		if(id==user[i].id){
			return i;
		}
	}
	return -1;
}

int main(){
	string cmd,usinguser;
	int usingindex = -1;
	int deposit,withdraw;
	vector<account> user;
	while(cin>>cmd){
		if(cmd=="create"){
			account a1;
			bool notexist=1;
			cin>>a1.id>>a1.password;
			int find=finduser(user,a1.id);
			if(find>=0){
				cout<<a1.id<<" existed, please change id\n";
			}
			else{
				user.push_back(a1);
				cout<<a1.id<<" created\n";
			}
		}
		else if(cmd=="login"){
			string id,password;
			cin >> id >> password;
			bool notexist=1;
			if(usingindex>=0){
				cout<<"Someone else is using!\n";
				continue;
			}
			int find=finduser(user,id);
			if(find>=0){
				if(password == user[find].password){
					cout<<"Welcome "<<user[find].id<<"\n";
					usingindex=find;
				}
				else{
					cout<<"Wrong password, please try again\n";					
				}
			}
			else{
				cout<<"Can't find "<<id<<", please try again\n";				
			}
		}
		else if(cmd=="logout"){
			if(usingindex==-1){
				cout<<"No one is using!\n";
			}
			else{
				cout<<"Goodbye "<<usinguser<<"\n";
				usingindex=-1;
			}
		}

		else if(cmd=="check"){
			if(usingindex == -1){
				cout<<"No one is using!\n";
			}
			else{
				cout<<"You have "<<user[usingindex].balance<<"\n";
			}
		}
		else if(cmd=="deposit"){
			if(usingindex==-1){
				cout<<"No one is using!\n";
			}
			else{
				cin>>deposit;
				user[usingindex].balance += deposit;
				cout<<deposit<<" saved\n";
			}
		}
		else if(cmd=="withdraw"){
			if(usingindex==-1){
				cout<<"No one is using!\n";
			}
			else{
				cin>>withdraw;
				if(user[usingindex].balance<withdraw){
					cout<<"Not enough\n";
				}
				else{
					user[usingindex].balance -= withdraw;
					cout<<withdraw<<" withdrew\n";
				}
			}
		}
		else if(cmd=="transfer"){
			if(usingindex>=0){
				int amount;
				string targetid;
				cin>>amount>>targetid;
				if(user[usingindex].balance<amount){
					cout<<"Not enough\n";
				}
				else{
					int finds=finduser(user,targetid);
					if(finds>=0){
						user[usingindex].balance -= amount;
						user[finds].balance += amount;
						cout<<amount<<" transferred to "<<targetid<<"\n";
					}
					else{
						cout<<"Can't find "<<targetid<<"\n";
					}	
				}
			}
			else{
				cout<<"No one is using!\n";
			}
		}
		else if(cmd == "shutdown"){
			break;
		}
		else{
			cout<<"Cannot find command "<<cmd<<" , please try again\n";
		}
	}
}


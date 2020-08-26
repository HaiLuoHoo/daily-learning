using namespace std;
#include<iostream>
#include<stack>
#define endl '\n'
int main(){
	stack<int> rem;
	int n,m;
	char hex[7]="ABCDEF";
	cout<<"请输入一个十进制正整数：";
	cin>>n;
	cout<<"您打算将其转换为m进制(m取2,8,10,16)：";
	cin>>m;
	while(m!=2&&m!=8&&m!=16&&m!=10){
		cout<<"请确保您输入的m进制为2,8,10,16中的一个值：";
		cin>>m; 
	}
	int div=n;
	while(div){
		rem.push(div%m);
		div/=m;
	}
	cout<<n<<"转换为"<<m<<"进制为:";
	while(!rem.empty()){
		if(m==16){
			if(rem.top()>=10){
				cout<<hex[rem.top()-10];
				rem.pop();
			}
			else{
				cout<<rem.top();
				rem.pop();
			}
				
		}
		else{
			cout<<rem.top();
			rem.pop();
		}
	}
	cout<<endl;
	return 0;
} 

using namespace std;
#include<iostream>
#include<stack>
#define endl '\n'
int main(){
	stack<int> rem;
	int n,m;
	char hex[7]="ABCDEF";
	cout<<"������һ��ʮ������������";
	cin>>n;
	cout<<"�����㽫��ת��Ϊm����(mȡ2,8,10,16)��";
	cin>>m;
	while(m!=2&&m!=8&&m!=16&&m!=10){
		cout<<"��ȷ���������m����Ϊ2,8,10,16�е�һ��ֵ��";
		cin>>m; 
	}
	int div=n;
	while(div){
		rem.push(div%m);
		div/=m;
	}
	cout<<n<<"ת��Ϊ"<<m<<"����Ϊ:";
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

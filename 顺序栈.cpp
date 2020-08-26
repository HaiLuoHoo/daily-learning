using namespace std;
#include<iostream>
#define endl '\n'
//˳��ջ 
class SqStack{
	private:
		int *base;
		int top;
		int stacksize;
	public:
		SqStack(int m);//����һ������Ϊm��ջ
		~SqStack(){
			delete[] base;
			top=-1;
			stacksize=0;
		}
		void push(int e);//��ջ 
		int pop();//��ջ 
		int getTop();//��ȡջ��Ԫ�� 
		bool isEmpty();//ջ�Ƿ�Ϊ�� 
		void stackTranverse();//��ʾջԪ�� 
};
SqStack::SqStack(int m){
	base=new int(m);
	top=-1;
	stacksize=m;
}
void SqStack::push(int e){
	if(top==stacksize-1){
		cout<<"ջ�����޷���ջ"<<endl; 
	}
	else{
		top++;
		base[top]=e;
	}
}
int SqStack::pop(){
	int e;
	if(top==-1){
		cout<<"ջ�գ��޷���ջ"<<endl;
		return -1; 
	}
	else{
		e=base[top--];
		return e;
	}
}
int SqStack::getTop(){
	if(top==-1){
		cout<<"ջ�գ�û��ջ��Ԫ��"<<endl;
		return -1;
	}
	else
		return base[top];
}
bool SqStack::isEmpty(){
	if(top==-1)
		return true;
	return false;
}
void SqStack::stackTranverse(){
	for(int i=0;i<=top;i++){
		cout<<base[i]<<' ';
	}
	cout<<endl;
}
int main(){
	int m,n,x;
	cout<<"������ջ������";
	cin>>m;
	SqStack stack(m);
	cout<<"�������㽫��ջ��Ԫ�ظ�����";
	cin>>n;
	cout<<"�������㽫��ջ��Ԫ��:"<<endl;
	for(int i=0;i<n;i++){
		cin>>x;
		stack.push(x);
	}
	cout<<"ջ��Ԫ���У�"; 
	stack.stackTranverse();
	cout<<"ջ��Ԫ��Ϊ��"<<stack.getTop()<<endl;
	cout<<endl; 
	for(int i=0;i<n;i++){
		cout<<"����ջ��Ԫ��"<<stack.pop()<<endl;
		cout<<"ջ��Ԫ���У�"; 
		stack.stackTranverse();
		cout<<"ջ�Ƿ�Ϊ�գ�"<<stack.isEmpty()<<"(0�����1������)"<<endl;
		cout<<"*************************************"<<endl;
	}
	return 0;
}

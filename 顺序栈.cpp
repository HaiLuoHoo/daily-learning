using namespace std;
#include<iostream>
#define endl '\n'
//顺序栈 
class SqStack{
	private:
		int *base;
		int top;
		int stacksize;
	public:
		SqStack(int m);//构建一个长度为m的栈
		~SqStack(){
			delete[] base;
			top=-1;
			stacksize=0;
		}
		void push(int e);//入栈 
		int pop();//出栈 
		int getTop();//获取栈顶元素 
		bool isEmpty();//栈是否为空 
		void stackTranverse();//显示栈元素 
};
SqStack::SqStack(int m){
	base=new int(m);
	top=-1;
	stacksize=m;
}
void SqStack::push(int e){
	if(top==stacksize-1){
		cout<<"栈满，无法入栈"<<endl; 
	}
	else{
		top++;
		base[top]=e;
	}
}
int SqStack::pop(){
	int e;
	if(top==-1){
		cout<<"栈空，无法出栈"<<endl;
		return -1; 
	}
	else{
		e=base[top--];
		return e;
	}
}
int SqStack::getTop(){
	if(top==-1){
		cout<<"栈空，没有栈顶元素"<<endl;
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
	cout<<"请输入栈容量：";
	cin>>m;
	SqStack stack(m);
	cout<<"请输入你将入栈的元素个数：";
	cin>>n;
	cout<<"请输入你将入栈的元素:"<<endl;
	for(int i=0;i<n;i++){
		cin>>x;
		stack.push(x);
	}
	cout<<"栈中元素有："; 
	stack.stackTranverse();
	cout<<"栈顶元素为："<<stack.getTop()<<endl;
	cout<<endl; 
	for(int i=0;i<n;i++){
		cout<<"弹出栈顶元素"<<stack.pop()<<endl;
		cout<<"栈中元素有："; 
		stack.stackTranverse();
		cout<<"栈是否为空："<<stack.isEmpty()<<"(0代表否，1代表是)"<<endl;
		cout<<"*************************************"<<endl;
	}
	return 0;
}

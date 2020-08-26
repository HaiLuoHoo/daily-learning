using namespace std;
#include<iostream>
#define endl '\n'
//链栈
struct node{
	int data;
	node *next;
};
class Stack{
	private:
		node *base;
		node *top;
	public:
		Stack();
		~Stack();
		void push(int e);//入栈 
		int pop();//出栈 
		int getTop();//获取栈顶元素 
		bool isEmpty();//栈是否为空 
		void stackTranverse();//显示栈元素 
};
Stack::Stack(){
	base=0;
	top=0;
}
Stack::~Stack(){
	
}
void Stack::push(int e){
	if(!base){
		base=new node;
		base->data=e;
		base->next=0;
		top=base;
	}
	else{
		node *p;
		p=new node;
		p->data=e;
		p->next=top;
		top=p;
	}
}
int Stack::pop(){
	if(!base){
		cout<<"栈空，无法出栈"<<endl;
		return -1; 
	}
	else{
		int e;
		node *p;
		p=top;
		top=top->next;
		e=p->data;
		delete p;
		return e;
	}
}
int Stack::getTop(){
	if(!base){
		cout<<"栈空，没有栈顶元素"<<endl;
		return -1; 
	}
	else{
		int e;
		e=top->data;
		return e;
	}
}
bool Stack::isEmpty(){
	if(!base)
		return true; 
	else
		return false;
}
void Stack::stackTranverse(){
	node *p;
	p=top;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
}
int main(){
	Stack stack;
	int n,x; 
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

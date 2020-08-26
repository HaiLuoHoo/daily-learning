using namespace std;
#include<iostream>
#define endl '\n'
//��ջ
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
		void push(int e);//��ջ 
		int pop();//��ջ 
		int getTop();//��ȡջ��Ԫ�� 
		bool isEmpty();//ջ�Ƿ�Ϊ�� 
		void stackTranverse();//��ʾջԪ�� 
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
		cout<<"ջ�գ��޷���ջ"<<endl;
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
		cout<<"ջ�գ�û��ջ��Ԫ��"<<endl;
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

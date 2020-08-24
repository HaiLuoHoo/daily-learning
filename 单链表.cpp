using namespace std;
#include<iostream>
#define endl '\n'
//实现链表的遍历插入和删除操作 
struct Node{
	int data;
	Node *next;
};
class LinkList{
	private:
		Node *head;
	public:
		LinkList();
		~LinkList();
		void CreateList1(int n);//头插法 
		void CreateList2(int n);//尾插法 
		void ListInsert(int i,int e);//插入元素e到第i个位置 
		void ListDelete(int n);//删除第n个元素 
		int GetElem(int i);//获取第i个元素 
		void GetList();
		int ListLength();//获取链表的长度 
};
LinkList::LinkList(){
	head=0;
}
void LinkList::CreateList1(int n){
	Node *p,*q;
	head=0;
	cout<<"请依次输入"<<n<<"个数据元素值:"<<endl;
	for(int i=0;i<n;i++){
		p=head;
		q=new Node;
		cin>>q->data;
		head=q;
		q->next=p;
	}
}
void LinkList::CreateList2(int n){
	Node *p,*q;
	p=head;
	cout<<"请依次输入"<<n<<"个数据元素值:"<<endl;
	for(int i=0;i<n;i++){
		if(i==0){
			p=new Node;
			cin>>p->data;
			p->next=0;
			head=p;
		}
		else{
			q=new Node;
			cin>>q->data;
			q->next=0;
			p->next=q;
			p=q;
		}
	}
}
void LinkList::ListInsert(int i,int e){
	Node *p,*q,*r;
	p=head;
	if(i==1){
		r=new Node;
		r->data=e;
		r->next=p;
		head=r; 
	}
	else{
		for(int j=0;j<i-2;j++){
			p=p->next;
		}
		q=p->next;
		r=new Node;
		r->data=e;
		r->next=q;
		p->next=r;
	}
}
void LinkList::ListDelete(int n){
	Node *p,*q;
	p=head;
	if(n==1){
		head=p->next;
		delete p;
	}
	else{
		for(int j=0;j<n-2;j++){
			p=p->next;
		}
		q=p->next;
		p->next=q->next;
		delete q;
	}
}
int LinkList::GetElem(int i){
	Node *p;
	p=head;
	for(int j=0;j<i-1;j++){
		p=p->next;
	}
	return p->data;
}
void LinkList::GetList(){
	Node *p;
	int n;
	p=head;
	while(p){
		cout<<p->data<<' ';
		p=p->next;
	}
	cout<<endl;
}
int LinkList::ListLength(){
	Node *p;
	int n=0;
	p=head;
	while(p){
		p=p->next;
		n++;
	}
	return n;
}
LinkList::~LinkList(){
	Node *p=0;
	while(p){
		p=head->next;
		delete head;
		head=p;
	}
}
int main(){
	LinkList list1;
	list1.CreateList1(6);
	cout<<list1.GetElem(4)<<endl;
	list1.GetList();
	list1.ListInsert(2,999);
	list1.GetList();
	cout<<"链表的长度："<<list1.ListLength()<<endl;
	list1.ListDelete(2);
	list1.GetList();
	cout<<"****************************************"<<endl;
	LinkList list2;
	list2.CreateList2(6);
	cout<<list2.GetElem(4)<<endl;
	list2.GetList();
	list2.ListInsert(2,999);
	list2.GetList();
	cout<<"链表的长度："<<list2.ListLength()<<endl;
	list2.ListDelete(2);
	list2.GetList();
	return 0;
}

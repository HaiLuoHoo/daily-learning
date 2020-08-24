using namespace std;
#include<iostream>
#define endl '\n'
//ʵ������ı��������ɾ������ 
struct Node{
	int data;
	Node *next;
};
class LinkList{
	private:
		Node *head;
	public:
		LinkList(){};
		~LinkList();
		void CreateList1(int n);//ͷ�巨 
		void CreateList2(int n);//β�巨 
		void ListInsert(int i,int e);//����Ԫ��e����i��λ�� 
		void ListDelete(int n);//ɾ����n��Ԫ�� 
		int GetElem(int i);//��ȡ��i��Ԫ�� 
		void GetList();
		int ListLength();//��ȡ����ĳ��� 
};
void LinkList::CreateList1(int n){
	Node *p,*q;
	head=0;
	cout<<"����������"<<n<<"������Ԫ��ֵ:"<<endl;
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
	cout<<"����������"<<n<<"������Ԫ��ֵ:"<<endl;
	for(int i=0;i<n;i++){
		q=new Node;
		cin>>q->data;
		q->next=0;
		p->next=q;
		p=q;
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
	cout<<"����ĳ��ȣ�"<<list1.ListLength()<<endl;
	list1.ListDelete(2);
	list1.GetList();
	return 0;
}

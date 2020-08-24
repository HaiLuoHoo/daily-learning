using namespace std;
#include<iostream>
#define MaxSize 1000
#define endl '\n'
//静态链表 
struct Node{
	int data;
	int next;
};
Node VList[MaxSize];
class LinkList{
	private:
		int head;
		int avail;
	public:
		LinkList();
		~LinkList(){};
		void CreateList1(int n);//头插法 
		void CreateList2(int n);//尾插法 
		void ListInsert(int i,int e);//插入元素e到第i个位置 
		void ListDelete(int n);//删除第n个元素 
		int GetElem(int i);//获取第i个元素 
		void GetList();
		int GetNode();
		int ListLength();//获取链表的长度 
};
LinkList::LinkList(){
	head=-1;
	avail=0;
	int i=0;
	for(;i<MaxSize-1;i++){
		VList[i].next=i+1;
	}
	VList[i].next=-1;
}
void LinkList::CreateList1(int n){
	int p,q;
	cout<<"请依次输入"<<n<<"个数据元素值:"<<endl;
	for(int i=0;i<n;i++){
		if(avail==-1){
			cout<<"表已满，没有空余的单元"<<endl;
			break;
		}
		else{
			p=head;
			q=avail;
			avail=VList[q].next;
			cin>>VList[q].data;
			head=q;
			VList[q].next=p;
		}
	}
}
void LinkList::CreateList2(int n){
	int p,q;
	cout<<"请依次输入"<<n<<"个数据元素值:"<<endl;
	for(int i=0;i<n;i++){
		if(avail==-1){
			cout<<"表已满，没有空余的单元"<<endl;
			break;
		}
		else{
			if(i==0){
				p=avail;
				avail=VList[p].next;
				cin>>VList[p].data;
				VList[p].next=-1;
				head=p;
			}
			else{
				q=avail;
				avail=VList[q].next;
				cin>>VList[q].data;
				VList[q].next=-1;
				VList[p].next=q;
				p=q;
			}
		}
	}
}
void LinkList::ListInsert(int i,int e){
	int p,q,r;
	p=head;
	if(avail==-1){
		cout<<"表已满，没有空余的单元"<<endl;
	}
	else{
		if(i==1){
			r=avail;
			avail=VList[r].next;
			VList[r].data=e;
			VList[r].next=p;
			head=r; 
		}
		else{
			for(int j=0;j<i-2;j++){
				p=VList[p].next;
			}
			q=VList[p].next;
			r=avail;
			avail=VList[r].next;
			VList[r].data=e;
			VList[r].next=q;
			VList[p].next=r;
		}
	}
}
void LinkList::ListDelete(int n){
	int p,q;
	p=head;
	if(n==1){
		head=VList[p].next;
		VList[p].next=VList[avail].next;
		avail=p;
	}
	else{
		for(int j=0;j<n-2;j++){
			p=VList[p].next;
		}
		q=VList[p].next;
		VList[p].next=VList[q].next;
		VList[q].next=VList[avail].next;
		avail=q;
	}
}
int LinkList::GetElem(int i){
	int p;
	p=head;
	for(int j=0;j<i-1;j++){
		p=VList[p].next;
	}
	return VList[p].data;
}
void LinkList::GetList(){
	int p;
	int n;
	p=head;
	while(p!=-1){
		cout<<VList[p].data<<' ';
		p=VList[p].next;
	}
	cout<<endl;
}
int LinkList::ListLength(){
	int p;
	int n=0;
	p=head;
	while(p!=-1){
		p=VList[p].next;
		n++;
	}
	return n;
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

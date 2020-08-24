using namespace std;
#include<iostream>
#define MaxSize 1000
#define endl '\n'
//��̬���� 
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
		void CreateList1(int n);//ͷ�巨 
		void CreateList2(int n);//β�巨 
		void ListInsert(int i,int e);//����Ԫ��e����i��λ�� 
		void ListDelete(int n);//ɾ����n��Ԫ�� 
		int GetElem(int i);//��ȡ��i��Ԫ�� 
		void GetList();
		int GetNode();
		int ListLength();//��ȡ����ĳ��� 
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
	cout<<"����������"<<n<<"������Ԫ��ֵ:"<<endl;
	for(int i=0;i<n;i++){
		if(avail==-1){
			cout<<"��������û�п���ĵ�Ԫ"<<endl;
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
	cout<<"����������"<<n<<"������Ԫ��ֵ:"<<endl;
	for(int i=0;i<n;i++){
		if(avail==-1){
			cout<<"��������û�п���ĵ�Ԫ"<<endl;
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
		cout<<"��������û�п���ĵ�Ԫ"<<endl;
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
	cout<<"����ĳ��ȣ�"<<list1.ListLength()<<endl;
	list1.ListDelete(2);
	list1.GetList();
	cout<<"****************************************"<<endl;
	LinkList list2;
	list2.CreateList2(6);
	cout<<list2.GetElem(4)<<endl;
	list2.GetList();
	list2.ListInsert(2,999);
	list2.GetList();
	cout<<"����ĳ��ȣ�"<<list2.ListLength()<<endl;
	list2.ListDelete(2);
	list2.GetList();
	return 0;
} 

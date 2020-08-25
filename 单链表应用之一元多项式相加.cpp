using namespace std;
#include<iostream>
#define endl '\n'
#define MAX 20
//ʹ�õ�����ʵ��һԪ����ʽ�ļӷ� 
typedef struct node{
	float coef;
	int exp;
}PolyArray[MAX];
struct PolyNode{
	float coef;
	int exp;
	PolyNode *next;
};
class Poly{
	private:
		PolyNode *head;
	public:
		Poly();
		~Poly();
		void CreatePoly(PolyArray a,int n);//β�巨����һԪ����ʽ 
		void PolyDisplay();//����ʽ��ʾ
		void PolySort();//��������� 
		void PolyAdd(Poly LB);//����ʽ��
};
Poly::Poly(){
	head=0;
}
void Poly::CreatePoly(PolyArray a,int n){
	PolyNode *p,*q;
	p=new PolyNode;
	p->exp=-1;
	p->next=0;
	head=p;
	for(int i=0;i<n;i++){
		q=new PolyNode;
		q->coef=a[i].coef;
		q->exp=a[i].exp;
		q->next=0;
		p->next=q;
		p=q;
	}
}
void Poly::PolySort(){
	PolyNode *p1,*p2,*p3,*r=0;
	p1=head;
	p2=p1->next;
	p3=p2->next;
	//ð������ 
	while(p3!=r){
		while(p3!=r){
			if(p2->exp>p3->exp){
				p2->next=p3->next;
				p1->next=p3;
				p3->next=p2;
			}
			p1=p2;
			p2=p3;
			p3=p3->next;
		}
		r=p2;
		p1=head;
		p2=p1->next;
		p3=p2->next;
	}
}
void Poly::PolyAdd(Poly LB){
	PolyNode *pa,*pb,*qa,*qb;
	pa=head;
	qa=pa->next;
	pb=LB.head;
	qb=pb->next;
	while(qb){
		if(qa==0){
			pa->next=qb;
			qb=0;
		}
		else{
			if(qb->exp<qa->exp){
				pb->next=qb->next;
				pa->next=qb;
				qb->next=qa;
				qa=qb;
				qb=pb->next;
			}
			else if(qb->exp>qa->exp){
				pa=qa;
				qa=qa->next;
			}
			else{
				pb->next=qb->next;
				if(qa->coef+qb->coef==0){
					pa->next=qa->next;
					delete qa;
					qa=pa->next;
				}
				else{
					qa->coef=qa->coef+qb->coef;
					pa=qa;
					qa=qa->next;
				}
				delete qb;
				qb=pb->next;
			}
		}
	}
}
void Poly::PolyDisplay(){
	char a;
	PolyNode *p;
	p=head->next;
	if(p->exp==0)
		cout<<p->coef;
	else if(p->exp==1)
		cout<<p->coef<<"x";
	else
		cout<<p->coef<<"x^"<<p->exp;
	p=p->next;
	while(p){
		if(p->coef>0){
			if(p->exp==0){
				cout<<'+'<<p->coef;
				p=p->next;
			}
			else if(p->exp==1){
				cout<<'+'<<p->coef<<"x";
				p=p->next;
			}
			else{
				cout<<'+'<<p->coef<<"x"<<'^'<<p->exp;
				p=p->next;
			}
		}
		else{
			if(p->exp==0){
				cout<<p->coef;
				p=p->next;
			}
			else if(p->exp==1){
				cout<<p->coef<<"x";
				p=p->next;
			}
			else{
				cout<<p->coef<<"x"<<'^'<<p->exp;
				p=p->next;
			}
		}
	}
	cout<<endl;
	
}
Poly::~Poly(){
	PolyNode *p=0;
	while(p){
		p=head->next;
		delete head;
		head=p;
	}
}
int main(){
	Poly LA,LB;
	PolyArray la,lb;
	int m,n;
	cout<<"������һԪ����ʽLA��������";
	cin>>m;
	cout<<"�����������ϵ���ʹ�����"<<endl;
	for(int i=0;i<m;i++){
		cin>>la[i].coef;
		cin>>la[i].exp; 
	}
	cout<<"������һԪ����ʽLB��������";
	cin>>n;
	cout<<"�����������ϵ���ʹ�����"<<endl;
	for(int i=0;i<n;i++){
		cin>>lb[i].coef;
		cin>>lb[i].exp; 
	}
	LA.CreatePoly(la,m);
	LB.CreatePoly(lb,n);
	cout<<"����ʽLA��";
	LA.PolyDisplay();
	cout<<"����ʽLB��";
	LB.PolyDisplay();
	LA.PolySort();
	LB.PolySort();
	cout<<"����ʽLA�����";
	LA.PolyDisplay();
	cout<<"����ʽLB�����";
	LB.PolyDisplay();
	LA.PolyAdd(LB);
	cout<<"����ʽLA�����ʽLB��Ӻ�";
	LA.PolyDisplay();
	return 0;
}

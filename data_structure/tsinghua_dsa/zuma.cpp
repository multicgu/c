#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct node {
	char bead;
	struct node * pred;
	struct node * succ;
}Node;
class list {
	private:
		Node * head;
		Node * tail;
		int size;
	public:
		Node * first;
		Node * last;
		list(int n=0):size(n) {
			head = new Node;
			tail = new Node;
			head->pred = NULL;
			head->succ = tail;
			tail->succ = NULL;
			tail->pred = head;
			head->bead = 0;
			tail->bead = 0;
		}
		int getsize() {return size;}
		void insert(char a,int n) {  //insert char & insert rank;
			Node * temp = head;
			for(int i=0; i<n; i++)
				temp = temp->succ;
			Node * ins = new Node;
			ins->pred = temp;
			ins->succ = temp->succ;
			temp->succ->pred = ins;
			temp->succ = ins;
			ins->bead = a;
			size++;
			int same=0;
			bool tag = 1;
			Node * cal = head->succ;
			while(size>2 && cal != tail) {
				Node * temp = NULL;
				while(cal->bead == cal->succ->bead) {
					same++;
					cal = cal->succ;
					temp = cal->succ;
				}
				//printf("same=%d,size=%d\n",same,size);
				if(same >= 2) {
					tag = 1;
					for(int i=0;i<=same;i++) {
						cal = cal->pred;
						delete [] cal->succ;
						size--;
						cal->succ = temp;
						temp->pred = cal;
					}
					cal = head;
				}
				else tag=0;
				same = 0;
				cal = cal->succ;
			}
		}
		int search(char a) {             //return the rank,if no same,renturn -1;
			Node * temp = tail->pred;
			int i=size-1;
			while(temp->bead != a || temp == head) {
				temp=temp->pred;
				i--;
			}
			return size;
		}
		void removeall() {
			Node * temp = head->succ;
			while(temp != tail) {
				temp = temp->succ;
				delete [] temp->pred;
				size--;
			}
		}
		~list() {
			removeall();
			delete [] head;
			delete [] tail;
		}
		void show() {
			if(size==0) 
				printf("-\n");
			else {
				Node * temp = head->succ;
				for(int i=0; i<size; i++,temp=temp->succ)
					printf("%c",temp->bead);
				printf("\n");
			}
		}
		friend void getlist(char * arr,list * N);
};
void getlist(char * arr,list * N) {
	int size = N->getsize();
	if(size==0) {
		arr[0]='-';
		arr[1]='\0';
	}
	else {
		Node * t = N->head->succ;
		for(int i = 0;i<size;i++) {
			arr[i] = t->bead;
			t=t->succ;
		}
		arr[size]='\0';
	}
}
int main() {
	char inbuf[20];
	char outbuf[20];
	setvbuf(stdin,inbuf,_IOLBF,20);
	setvbuf(stdin,outbuf,_IOFBF,20);
	list l;
	char * bead = new char[20001];
	gets(bead);       //get origin char list
	//scanf("%s",bead);
	//printf("bead=%s\n",bead);
	for(int i=0; bead[i]!='\0'; i++) //insert origin list to the class;
		l.insert(bead[i],i);
	delete [] bead;
	int n,inrank; //var n is the operator number.var inrank is the insert rank;
	scanf("%d",&n);
	char inchar;
	while(getchar()!='\n');
	char * show[n];
	for(int i=0;i<n;i++) {     //get the inrank;
		scanf("%d",&inrank);
		while(getchar()!=' ');
		inchar=getchar();    //get the insert char;
		l.insert(inchar,inrank);
		show[i] = new char[l.getsize()+2];
		getlist(show[i],&l);
	}
	for(int i=0;i<n;i++)
		printf("%s\n",show[i]);

	return 0;
}

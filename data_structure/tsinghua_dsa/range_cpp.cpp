#include<iostream>
#include<stdio.h>
using namespace std;
class range {
	public:
		unsigned int m;
		unsigned int (*nptr)[2];
		range(unsigned int i,unsigned int (*ar)[2]):m(i) {
			nptr = new unsigned int[m][2];
			for(unsigned int i=0;i<m;i++) {
				nptr[i][0] = ar[i][0];
				nptr[i][1] = ar[i][1];
			}
		} 
		~range() {delete [] nptr;}
		/*void show() {
			for(unsigned int i = 0; i<m; i++) 
				cout << nptr[i][0] << " " << nptr[i][1]<<endl;
		}*/
}; 
class list:public range {
	private:
		unsigned int n;
		unsigned int * p;
		void mergesort(unsigned int lo,unsigned int mi,unsigned int hi);
	public:
		list(unsigned int m,unsigned int (*ar)[2],unsigned int t,unsigned int * arr):range(m,ar),n(t) {
			p = new unsigned int[n];
			for(unsigned int i = 0;i<n;i++)
				p[i] = arr[i];
		}
		void merge(unsigned int lo,unsigned int hi);
		unsigned int binsearch(unsigned int s) {
			unsigned int lo=0;
			unsigned int hi=n;
			unsigned int mi;
			while((hi-lo)>0) {
				mi = (lo+hi)>>1;
				if(s<=p[mi]) hi = mi;
				if(p[mi]<s) lo = mi+1;
			}
			return lo;
		}
		unsigned int * getnum() {
			unsigned int * num=new unsigned int[m];
			for(unsigned int i=0;i<m;i++) {
				unsigned int r1 = binsearch(nptr[i][0]);
				unsigned int r2 = binsearch(nptr[i][1]);
				if(p[r2]==nptr[i][1]) num[i]= r2-r1+1;
				else num[i]=r2-r1;
			}
			return num;
		}
		~list() {delete [] p;}
		/*void show() {
			for(int i=0;i<n;i++)
				cout<<p[i] << " ";
			cout << endl;
		}*/
};
void list::mergesort(unsigned int lo,unsigned int mi,unsigned int hi) {
	unsigned int la = mi-lo;
	unsigned int lc = hi-mi;
	unsigned int a=0,b=0,c=0; //rank of the A,B,C;
	unsigned int *A = new unsigned int[la];
	for(unsigned int i=0; i<la;) {A[i++]=p[lo+i];}
	unsigned int *B = &p[lo];
	unsigned int *C = &p[mi];
	while(a<la) {
		if(c>=lc || A[a]<=C[c]) {B[b++] = A[a++];}
		if(c<lc && C[c]<A[a]) {B[b++] = C[c++];}
	}
}
void list::merge(unsigned int lo,unsigned int hi) {
	if(hi-lo<=1) return;
	unsigned int mi = (hi+lo)>>1;
	merge(lo,mi);
	merge(mi,hi);
	mergesort(lo,mi,hi);
}
int main() {
	unsigned int n,m;
	//cin >> n >> m;
	scanf("%d%d",&n,&m);
	unsigned int arr[n];
	for(unsigned int i = 0; i<n; i++)
		//cin >> arr[i];
		scanf("%d",&arr[i]);
	unsigned int a[m][2];
	for(unsigned int i = 0; i<m; i++) 
		//cin >> a[i][0] >> a[i][1];
		scanf("%d%d",&a[i][0],&a[i][1]);
	list l(m,a,n,arr);
	l.merge(0,n);
	unsigned int *num = new unsigned int[m];  
	num=l.getnum();
	for(unsigned int i=0;i<m;i++) 
		//cout<<num[i]<<endl;
		printf("%d\n",num[i]);
	delete [] num;
	return 0;
}

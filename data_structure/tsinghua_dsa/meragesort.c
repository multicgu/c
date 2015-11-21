#include<stdio.h>
#include<stdlib.h>
void showvector(int * vector,int n);
void mergesort(int * vector,int lo,int hi);
void merge(int * vector,int lo,int hi,int mi); 
int main(void)
{
	int vector[10] = {4,7,6,2,9,8,0,7,5,3};
	showvector(vector,10);
	mergesort(vector,0,10);
	showvector(vector,10);

	return 0;
}

void showvector(int * vector,int n) {
	int i;
	for(i=0;i<n;i++)
		printf("%d ",vector[i]);
	puts(" ");
}

void mergesort(int * vector,int lo,int hi) {
	if(hi-lo<2) return;
	int mi = (lo+hi)>>1;
	mergesort(vector,lo,mi);
	mergesort(vector,mi,hi);
	merge(vector,lo,hi,mi);
}

void merge(int * vector,int lo,int hi,int mi) {
	int i;
	int la = mi-lo, lb = hi-mi, lc = hi-lo; // for length of A,B,C;
	int * A = (int*)malloc(sizeof(int)*la); // vector A;
	int * B = vector + mi; // vector B;
	int * C = vector + lo; // vector C;
	for(i=0;i<mi;A[i]=C[i++]); // copy the before subsqu to B;

	int a,b; // for A,B rank;
	for(a=0,b=0,i=0; a<la;) {
		if((a<la) && ((b>=lb)||(A[a] <= B[b]))) 
			C[i++] = A[a++];
		if((b<lb) && ((a>=la)||(B[b] < A[a])))
			C[i++] = B[b++];
	}
	//showvector(vector,lc);
	//free(A);
}

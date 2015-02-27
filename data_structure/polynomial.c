//f(x)=1+ ... +(1/(i-1)*x^(i-1))+(1/i)*x^i; f(1.1)
#include<stdio.h>
#include<math.h>
#include<time.h>
clock_t start,stop,start1,start2;
double during;
double f1(unsigned long i,double x);
double f2(unsigned long i,double x);
void showduring(clock_t start,clock_t stop);
double x=1.1;
int main(void)
{
	unsigned long i=10000000;
	double a,b;
	//printf("f1=%lf\n",a=f1(i,x));
	//printf("f2=%lf\n",b=f2(i,x));
	start=clock();
	f1(i,x);
	stop=clock();
	showduring(start,stop);
	start=clock();
	f2(i,x);
	stop=clock();
	showduring(start,stop);
	/*during=((double)(stop-start))/CLK_TCK;
	printf("Ticket=%ff\n",(stop-start));
	printf("duration=%6.2e\n",during);*/

	return 0;
}
void showduring(clock_t start,clock_t stop)
{
	//during=((double)(stop-start))/CLK_TCK;
	printf("Ticket=%lf\n",(double)(stop-start));
	//printf("duration=%6.2e\n",during);
}
double f1(unsigned long i,double x)
{
	unsigned long n=1;
	double p=1;
	for(n=1;n<=i;n++)
		p+=(1/(double)n)*pow(x,n);
	return p;
}
double f2(unsigned long i,double x)
{
	unsigned long n;
	double p=0;
	for(n=i;n>0;n--)
		p=x*(1/(double)n)+x*p;
	p+=1;
	return p;
}

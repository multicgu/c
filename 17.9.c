// mall.c   with 17.6.h
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include "17.6.h"
#define MIN_PER_HR 60
bool newcustomer(double x);
Item customertime(int when);
int main(void)
{
	Queue line;
	Item temp;
	int hours;
	int cycle,cyclelimit; //循环计数，计数上限；
	int wait_time=0; //当前到空闲所需的时间；
	int perhour; //每小时的次数；
	int customers=0; //总的客户数；
	int served=0; //已经服务的人数；
	int turnaways=0; //超出队列的人数；
	int line_wait=0; //队列等待的时间;
	int ave_cust_time;//顾客到来的平均时间；
	int sum_line;    //队列的长度；
	initializequeue(&line);
	srand(time(0));
	puts("Case study: Sigmund Lander's Advice Booth");
	puts("Enter the number of simulation hours: ");
	scanf("%d",&hours);
	cyclelimit=hours*MIN_PER_HR;
	puts("Enter the average number of customers per hour: ");
	scanf("%d",&perhour);
	ave_cust_time=MIN_PER_HR/perhour;
	for(cycle=0;cycle<=cyclelimit;cycle++)
	{
		if(newcustomer(ave_cust_time))
		{
			if(queueisfull(&line))
				turnaways++;
			else
			{
				customers++;
				temp=customertime(cycle);
				enqueue(temp,&line);
			}
		}
		if(wait_time<=0 && !queueisempty(&line))
		{
			dequeue(&temp,&line);
			wait_time=temp.processtime;
			line_wait+=temp.processtime;
			served++;
		}
		if(wait_time>0)
			wait_time--;
		sum_line+=queueitems(&line);
	}
	if(customers>0)
	{
		printf("Customers accepted: %d\n",customers);
		printf("Customers served: %d\n",served);
		printf("Customers turnaways: %d\n",turnaways);
		printf("Average queue size: %.2f\n",(double)sum_line/cyclelimit);
		printf("Average wait time: %.2f minutes.\n",(double)line_wait/served);
	}
	return 0;
}
bool newcustomer(double x)
{
	if(rand()*x/RAND_MAX<1)
		return true;
	else
		return false;
}
Item customertime(int when)
{
	Item temp;
	temp.arrivetime=when;
	temp.processtime=(rand()%3+1);
	return temp;
}

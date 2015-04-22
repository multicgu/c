/*最大子列和问题
给定K个整数组成的序列{ N1, N2, ..., NK }，“连续子列”被定义为{ Ni, Ni+1, ..., Nj }，其中 1 <= i <= j <= K。“最大子列和”则被定义为所有连续子列元素的和中最大者。例如给定序列{ -2, 11, -4, 13, -5, -2 }，其连续子列{ 11, -4, 13 }有最大的和20。现要求你编写程序，计算给定整数序列的最大子列和。 */
#include<stdio.h>
int main(void)
{
	int n,i;
	fscanf(stdin,"%d",&n);
	int arr[n-1];
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	int max=0;
	int temp=0;
	for(i=0;i<n;i++)
	{
		temp+=arr[i];
		if(temp<0)
			temp=0;
		if(temp>=max)
			max=temp;
	}

	printf("%d\n",max);
	return 0;
}

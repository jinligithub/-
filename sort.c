#include"sort.h"

void InsertSort(int *a, int n)//插入排序
{
	assert(a);
	int i = 0;
	for (i = 0; i < n-1; i++)//只有用进行n-1趟就可以排序完成
	{
		int end = i;
		int x = 0;
		int tmp = a[end + 1];//提前保存好要插入的值
		while (end>=0 && a[end] > tmp)//如果a[end]>a[end+1],继续向后找比它小的数
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end+1] = tmp;
	}
}

void ShellSort(int *a, int n)//希尔排序
{
	assert(a);
	int i = 0;
	int gap = n / 2;//最开始分组的步长
	while (gap >= 1)//当步长大于等于一时停止排序，此时序列已经排好
	{
		for (i = 0; i < n - gap; i++)//同时进行 n-gad 的组交换
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end]>tmp)//去找比去找较小的数
			{
				a[end + gap] = a[end];
				end -= gap;//向前找
			}
			a[end + gap] = tmp;//找到位置，插入值
		}
		gap /= 2;//每次步长都变为之前步长的0.5倍
	}
}

void TestInsert()
{
	int a[] = { 45, 16, 98, 65, 32, 0, 3, 19 };
	InsertSort(a, sizeof(a) / sizeof(a[0]));
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
void TestShell()
{
	int a[] = { 45, 16, 98, 65, 32, 0, 3, 19 };
	ShellSort(a, sizeof(a) / sizeof(a[0]));
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
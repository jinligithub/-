#include"sort.h"

void InsertSort(int *a, int n)//��������
{
	assert(a);
	int i = 0;
	for (i = 0; i < n-1; i++)//ֻ���ý���n-1�˾Ϳ����������
	{
		int end = i;
		int x = 0;
		int tmp = a[end + 1];//��ǰ�����Ҫ�����ֵ
		while (end>=0 && a[end] > tmp)//���a[end]>a[end+1],��������ұ���С����
		{
			a[end + 1] = a[end];
			--end;
		}
		a[end+1] = tmp;
	}
}

void ShellSort(int *a, int n)//ϣ������
{
	assert(a);
	int i = 0;
	int gap = n / 2;//�ʼ����Ĳ���
	while (gap >= 1)//���������ڵ���һʱֹͣ���򣬴�ʱ�����Ѿ��ź�
	{
		for (i = 0; i < n - gap; i++)//ͬʱ���� n-gad ���齻��
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0 && a[end]>tmp)//ȥ�ұ�ȥ�ҽ�С����
			{
				a[end + gap] = a[end];
				end -= gap;//��ǰ��
			}
			a[end + gap] = tmp;//�ҵ�λ�ã�����ֵ
		}
		gap /= 2;//ÿ�β�������Ϊ֮ǰ������0.5��
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
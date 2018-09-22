void SelectSort(int *a, int n)//选择排序
{
	assert(a);
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		int max = begin;
		int min = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i]>a[max])//找出最大值的下标
				max = i;
			if (a[i] < a[min])//找出最小值的下标
				min = i;
		}
		if (begin != min)
			Swap(&a[begin], &a[min]);//把最小值放最前边
		if (begin == max)//解决最大值和最小值交换两次，又交换回去的问题
			max = min;
		if (end != max)
			Swap(&a[end], &a[max]);//把最大值放最后边
		++begin;
		--end;
	}
}
void TestSelect()
{
	int a[] = { 45, 16, 98, 65, 32, 0, 3, 19 };
	SelectSort(a, sizeof(a) / sizeof(a[0]));
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
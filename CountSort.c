void CountSort(int *a, int n)//计数排序
{
	assert(a);
	int max = a[0];
	int min = a[0];
	int i = 0;
	for (i = 0; i < n; i++)//找出最大最小值
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min - 1;//确定范围
	int *count = (int*)malloc(range*sizeof(int));//重新开辟一个数组
	memset(count, 0, range*sizeof(int));
	for (i = 0; i < n; ++i)
	{
		count[a[i] - min]++;//对应到count数组的相应位置
	}
	int index = 0;
	for (i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[index++] = i + min;//对应到a数组的相应的位置
		}
	}
}
void TestCount()
{
	int a[] = { 45, 16, 98, 65, 32, 0, 3, 19 };
	CountSort(&a, 8);
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
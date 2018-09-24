void AdjustDown(int *a, int n, int root)//向下调整法
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child<n)
	{
		if (child + 1<n&&a[child] < a[child + 1])//child+1防止越界，a[child] < a[child + 1]下一个数比当前的数大，就继续比较下一个数
			child++;
		if (a[child] > a[parent])//如果孩子大于父亲，两数交换
		{
			Swap(&a[child], &a[parent]);
			parent = child;//让父亲等于孩子
			child = parent * 2 + 1;//让孩子为父亲的左子树
		}
		else
		{
			break;
		}
	}

}
void HeapSort(int *a, int n)//堆排序
{
	assert(a);
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; --i)//(n-2)/2找到最后一个非叶子节点
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end >0)//把最大的数放最后
	{
		Swap(&a[0], &a[end]);//把第一个数和最后一个数交换
		AdjustDown(a, end, 0);//继续调整end之前的数，把最大值放在a[0]的位置
		end--;//end的向前移动一位，使最大值在后边保持不动
	}

}
void TestHeap()
{
	int a[] = { 45, 16, 98, 65, 32, 0, 3, 19 };
	HeapSort(a, sizeof(a) / sizeof(a[0]));
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
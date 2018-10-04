//归并排序，比快快排快一点，它是严格的二分
void Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp)//在不同的区间里排序，然后合并
{
	int start = begin1;
	int end = end2 - begin1 + 1;//对应子区间的元素个数
	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)//其中一个结束就结束了。//在这两个子区间域里排序，排好放在tmp里
	{
		//把小的放在tmp里
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//如果两个区间没有归并完，继续进行剩下元素的归并
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + start, tmp + start, sizeof(int)*end);//内存拷贝,在tmp里保存的数据最后还给 a
	//a + start, tmp + start, 要保证保存在对应的区间内
}

void _mergesort(int *a, int begin, int end, int *tmp)
{
	if (begin >= end)
		return;
	int mid = begin + ((end - begin) >> 1);
	//[begin ,mid] [mid+1,end]
	_mergesort(a, begin, mid, tmp);//分别在两个子区间里递归
	_mergesort(a, mid + 1, end, tmp);

	Merge(a, begin, mid, mid + 1, end, tmp);
}
void MergeSort(int *a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int)*n);//创建一个临时数组存储数据
	_mergesort(a, 0, n - 1, tmp);//排序数组，起始位置，结束位置，临时数组
	free(tmp);
	tmp = NULL;
}

void TestMerge()
{
	int a[] = { 45, 16, 98, 65, 32, 0, 3, 19 };
	MergeSort(a, 8);
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
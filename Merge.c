//�鲢���򣬱ȿ���ſ�һ�㣬�����ϸ�Ķ���
void Merge(int *a, int begin1, int end1, int begin2, int end2, int *tmp)//�ڲ�ͬ������������Ȼ��ϲ�
{
	int start = begin1;
	int end = end2 - begin1 + 1;//��Ӧ�������Ԫ�ظ���
	int index = begin1;
	while (begin1 <= end1&&begin2 <= end2)//����һ�������ͽ����ˡ�//�����������������������ź÷���tmp��
	{
		//��С�ķ���tmp��
		if (a[begin1] < a[begin2])
			tmp[index++] = a[begin1++];
		else
			tmp[index++] = a[begin2++];
	}
	//�����������û�й鲢�꣬��������ʣ��Ԫ�صĹ鲢
	while (begin1 <= end1)
		tmp[index++] = a[begin1++];
	while (begin2 <= end2)
		tmp[index++] = a[begin2++];
	memcpy(a + start, tmp + start, sizeof(int)*end);//�ڴ濽��,��tmp�ﱣ���������󻹸� a
	//a + start, tmp + start, Ҫ��֤�����ڶ�Ӧ��������
}

void _mergesort(int *a, int begin, int end, int *tmp)
{
	if (begin >= end)
		return;
	int mid = begin + ((end - begin) >> 1);
	//[begin ,mid] [mid+1,end]
	_mergesort(a, begin, mid, tmp);//�ֱ���������������ݹ�
	_mergesort(a, mid + 1, end, tmp);

	Merge(a, begin, mid, mid + 1, end, tmp);
}
void MergeSort(int *a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int)*n);//����һ����ʱ����洢����
	_mergesort(a, 0, n - 1, tmp);//�������飬��ʼλ�ã�����λ�ã���ʱ����
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
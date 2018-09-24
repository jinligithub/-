void AdjustDown(int *a, int n, int root)//���µ�����
{
	int parent = root;
	int child = 2 * parent + 1;
	while (child<n)
	{
		if (child + 1<n&&a[child] < a[child + 1])//child+1��ֹԽ�磬a[child] < a[child + 1]��һ�����ȵ�ǰ�����󣬾ͼ����Ƚ���һ����
			child++;
		if (a[child] > a[parent])//������Ӵ��ڸ��ף���������
		{
			Swap(&a[child], &a[parent]);
			parent = child;//�ø��׵��ں���
			child = parent * 2 + 1;//�ú���Ϊ���׵�������
		}
		else
		{
			break;
		}
	}

}
void HeapSort(int *a, int n)//������
{
	assert(a);
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; --i)//(n-2)/2�ҵ����һ����Ҷ�ӽڵ�
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end >0)//�������������
	{
		Swap(&a[0], &a[end]);//�ѵ�һ���������һ��������
		AdjustDown(a, end, 0);//��������end֮ǰ�����������ֵ����a[0]��λ��
		end--;//end����ǰ�ƶ�һλ��ʹ���ֵ�ں�߱��ֲ���
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
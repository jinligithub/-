void SelectSort(int *a, int n)//ѡ������
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
			if (a[i]>a[max])//�ҳ����ֵ���±�
				max = i;
			if (a[i] < a[min])//�ҳ���Сֵ���±�
				min = i;
		}
		if (begin != min)
			Swap(&a[begin], &a[min]);//����Сֵ����ǰ��
		if (begin == max)//������ֵ����Сֵ�������Σ��ֽ�����ȥ������
			max = min;
		if (end != max)
			Swap(&a[end], &a[max]);//�����ֵ������
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
void CountSort(int *a, int n)//��������
{
	assert(a);
	int max = a[0];
	int min = a[0];
	int i = 0;
	for (i = 0; i < n; i++)//�ҳ������Сֵ
	{
		if (a[i]>max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	int range = max - min - 1;//ȷ����Χ
	int *count = (int*)malloc(range*sizeof(int));//���¿���һ������
	memset(count, 0, range*sizeof(int));
	for (i = 0; i < n; ++i)
	{
		count[a[i] - min]++;//��Ӧ��count�������Ӧλ��
	}
	int index = 0;
	for (i = 0; i < range; ++i)
	{
		while (count[i]--)
		{
			a[index++] = i + min;//��Ӧ��a�������Ӧ��λ��
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
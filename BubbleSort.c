void BubbleSort(int *a, int n)//ц╟ещеепР
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		int flag = 0;
		for (j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}

void TestBubble()
{
	int a[] = { 45, 16, 98, 65, 32, 0, 3, 19 };
	BubbleSort(a, sizeof(a) / sizeof(a[0]));
	int i = 0;
	for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d  ", a[i]);
	}
	printf("\n");
}
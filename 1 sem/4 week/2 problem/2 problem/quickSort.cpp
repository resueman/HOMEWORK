void swap(int &a, int&b)
{
	int c = a;
	a = b;
	b = c;
}

int partition(int* arr, int left, int right)
{
	int first = arr[left];
	int i = left + 1;
	for (int j = left + 1; j < right + 1; ++j)
	{
		if (arr[j] <= first)
		{
			swap(arr[j], arr[i]);
			i++;
		}
	}
	swap(arr[left], arr[i - 1]);
	return i - 1;
}

void insertionSort(int* arr, int left, int right)
{
	for (int i = left; i < right; ++i)
	{
		int j = i + 1;
		while ((arr[j] < arr[j - 1]) && (j > 0))
		{
			swap(arr[j], arr[j - 1]);
			j--;
		}
	}
}

void quickSort(int* arr, int left, int right)
{
	if (right > left)
	{
		if (right - left + 1 < 10)
		{
			insertionSort(arr, left, right);
		}
		else
		{
			int pivot = partition(arr, left, right);
			quickSort(arr, left, pivot - 1);
			quickSort(arr, pivot + 1, right);
		}
	}
}
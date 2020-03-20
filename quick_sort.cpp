#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

int partition(int low, int high, int *a)
{
	int pivot = a[high];
	int i = low - 1;
	for(int j = low; j < high; j++)
	{
		if(a[j] < pivot)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[high]);
	return (i + 1);
}

void quick_sort(int low, int high, int *a)
{
	if(low < high)
	{
		int partition_index = partition(low, high, a);
		// cout << "partition_index: " << partition_index << "\n";
		quick_sort(low, partition_index - 1, a);
		quick_sort(partition_index + 1, high, a);
	}
}

int main() {
	int a[] = {14, 13, 20, 18, 24, 17};
	int array_size = (int)((int)(sizeof(a)) / (int)(sizeof(a[0])));
	quick_sort(0, array_size - 1, a);
	for(int i = 0; i < array_size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
	// your code goes here
	return 0;
}
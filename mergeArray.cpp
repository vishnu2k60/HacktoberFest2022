#include <iostream>
using namespace std;

void merge(int arr1[],int n1, int arr2[], 
							int n2, int arr3[])
{
	int i = 0, j = 0, k = 0;

	// Traverse both array
	while (i<n1 && j <n2)
	{
		// Check if current element of first
		// array is smaller than current element
		// of second array. If yes, store first
		// array element and increment first array
		// index. Otherwise do same with second array
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];
		else
			arr3[k++] = arr2[j++];
	}

	// Store remaining elements of first array
	while (i < n1)
		arr3[k++] = arr1[i++];

	// Store remaining elements of second array
	while (j < n2)
		arr3[k++] = arr2[j++];
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size1;
		cin >> size1;

		int *arr1 = new int[size1];

		for (int i = 0; i < size1; i++)
		{
			cin >> arr1[i];
		}

		int size2;
		cin >> size2;

		int *arr2 = new int[size2];

		for (int i = 0; i < size2; i++)
		{
			cin >> arr2[i];
		}

		int *ans = new int[size1 + size2];

		merge(arr1, size1, arr2, size2, ans);

		for (int i = 0; i < size1 + size2; i++)
		{
			cout << ans[i] << " ";
		}

		cout << endl;
		delete[] arr1;
		delete[] arr2;
		delete[] ans;
	}
}

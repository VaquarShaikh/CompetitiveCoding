#include <iostream>
using namespace std;

#include "solution.h"

int main()
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
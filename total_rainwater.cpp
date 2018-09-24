#include <iostream>
using namespace std;
int main()
{
	int test;
	cin >> test;
	while (test--)
	{
		int size;
		cin >> size;
		int arr[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		int max = arr[0], index = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] >= max)
			{
				max = arr[i];
				index = i;
			}
		}
		int low = 0, sum = 0;
		for (int i = 0; i <= index; i++)
		{

			if (arr[i] <= arr[low])
			{

				sum = sum + arr[low] - arr[i];
			}
			else
			{
				low = i;
			}
		}

		low = size - 1;
		for (int i = size - 1; i >= index; i--)
		{

			if (arr[i] <= arr[low])
			{
				sum = sum + arr[low] - arr[i];
			}
			else
			{
				low = i;
			}
		}
		cout << sum;

		//while ends
	}
	return 0;
}

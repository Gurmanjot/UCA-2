#include <iostream>
#include <stack>
using namespace std;
int main()
{
	stack<int> s;
	int max = 0, area, val;

	int arr[] = {6, 2, 5, 4, 5, 1, 6};
	int size = sizeof(arr) / sizeof(arr[0]);

	int i;
	for (i = 0; i < size; i++)
	{
		if (s.empty())
		{
			s.push(i);
		}
		else if (arr[s.top()] > arr[i])
		{
			val = arr[s.top()];
			s.pop();
			area = val * (s.empty() ? (i) : (i - 1 - s.top()));
			
			if (max < area)
				max = area;

			i--;
			continue;
		}
		else
		{
			s.push(i);
		}
	}

	while (!s.empty())
	{
		val = arr[s.top()];
		s.pop();
		area = val * (s.empty() ? (i) : (i - s.top() - 1));
		if (area > max)
			max = area;
		
	}

	cout << "max = " << max;
	return 0;
}

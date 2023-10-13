#include <iostream>
using namespace std;

int heap[100001];
int heapCount = 0;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void pop()
{
	if (heapCount == 0)
	{
		cout << 0 << '\n';
		return;
	}
	cout << heap[1] << '\n';

	swap(&heap[1], &heap[heapCount]);
	heapCount--;

	int parent = 1;
	int child = parent * 2;
	if (child + 1 <= heapCount)
		child = heap[child] < heap[child + 1] ? child : child + 1;
	
	while (child <= heapCount && heap[parent] > heap[child])
	{
		swap(&heap[parent], &heap[child]);
		parent = child;
		child= child * 2;
		if (child + 1 <= heapCount)
			child = heap[child] < heap[child + 1] ? child : child + 1;
	}
}

void push(int data)
{
	heapCount += 1;
	heap[heapCount] = data;

	int child = heapCount;
	int parent = child / 2;

	while (child > 1 && heap[parent] > heap[child])
	{
		swap(&heap[parent], &heap[child]);
		child = parent;
		parent = child / 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int x;
	for(int i = 0; i < N; i++)
	{
		cin >> x;
		if (x == 0) pop();
		else push(x);
	}

	return 0;
}
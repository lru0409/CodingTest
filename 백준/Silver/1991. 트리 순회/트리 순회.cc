#include <iostream>
using namespace std;

int tree[26][2];

void preorder(int root)
{
	if (root < 0) return;
	cout << (char)(root + 'A');
	preorder(tree[root][0]);
	preorder(tree[root][1]);
}

void inorder(int root)
{
	if (root < 0) return;
	inorder(tree[root][0]);
	cout << (char)(root + 'A');
	inorder(tree[root][1]);
}

void postorder(int root)
{
	if (root < 0) return;
	postorder(tree[root][0]);
	postorder(tree[root][1]);
	cout << (char)(root + 'A');
}

int main()
{
	int N;
	cin >> N;

	char node, left, right;
	for(int i = 0; i < N; i++)
	{
		cin >> node >> left >> right;
		tree[node - 'A'][0] = left - 'A';
		tree[node - 'A'][1] = right - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);
	cout << '\n';

	return (0);
}

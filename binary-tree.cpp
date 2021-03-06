#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

typedef struct tree
{
	int key;
	struct tree *left;
	struct tree *right;
} node;

node *create(int key)
{
	node *tmp = (node *)malloc(sizeof(node));
	tmp->key = key;
	tmp->left = tmp->right = NULL;

	return tmp;
}

void add(node *root, int value)
{
	if (root->key == NULL) {
		create(value);
	}
	else {
		if (root->key <= value) {
			if (root->right == NULL) {
				root->right = create(value);
			}
			else {
				add(root->right, value);
			}
		}
		if (root->key > value) {
			if (root->left == NULL) {
				root->left = create(value);
			}
			else {
				add(root->left, value);
			}
		}
	}

}

int search(node *root, int key)
{
	if (root->key == key)
		return 1;
	if (key > root->key)
		return search(root->right, key) + 1;
	return search(root->left, key) + 1;
}

int main() {

	setlocale(LC_ALL, "Russian");

	int a[1001];

	srand(time(NULL));

	for (int i = 0; i < 1000; i++) {
		a[i] = rand() % 2000;
		//cout << a[i] << ' ';
	}
	a[1000] = 2000;

	node *root = create(a[0]);

	for (int i = 1; i < 1000; i++) {
		add(root, a[i]);
	}

	int num;
	cout << ("Введите число: ");
	cin >> num;

	int i;
	for (i = 0; i < 1001; i++) {
		if (a[i] == num) break;
	}
	int time1 = i, time2;
	if (time1 == 1001) cout << "Этого элемента нет в массиве";
	else {
		time2 = search(root, num);
		cout << "Операций в прямом поиске: " << time1 << endl;
		cout << "Операций в поиске деревом: " << time2;
	}

	return 0;
}

/*По входной последовательности целых чисел построить бинарное дерево. Найти для
каждой вершины дерева сумму её предков.
*/

#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>

using namespace std;

struct TreeNode
{
    int info;
    TreeNode* left, * right;
};

TreeNode* makeTree(int level);
void printTree(TreeNode*& root, const int level = 0);
void sumOfPredoks(TreeNode* root, vector<int>& sums, int sum = 0);
void printSum(vector<int> arr);

int main()
{
	setlocale(LC_ALL, "Russian");
	vector<int> sums;

	cout << "Введите дерево" << endl;
	TreeNode* root = makeTree(0);

	cout << "Введенное дерево:" << endl;
	printTree(root);
	sumOfPredoks(root, sums);

	cout << "Сумма предков вершин дерева слева направо:" << endl;
	printSum(sums);
}

// Создание бинарного дерева вводом с клавиатуры
TreeNode* makeTree(int level)
{
	char c;
	cout << setw(4 * level) << "" << "Создать вершину? (y/n)";
	cin >> c;
	if (c == 'y')
	{
		TreeNode* p = new TreeNode;
		cout << setw(4 * level) << "" << "Введите значение вершины:";
		cin >> p->info;

		cout << setw(4 * level) << "" << "Левое поддерево вершины " << p->info << endl;
		p->left = makeTree(level + 1);

		cout << setw(4 * level) << "" << "Правое поддерево вершины " << p->info << endl;
		p->right = makeTree(level + 1);
		return p;
	}
	else
		return NULL;


}


// Вывод бинарного дерева на консоль
void printTree(TreeNode*& root, const int level)
{
	if (root)
	{
		printTree(root->left, level + 1);
		cout << setw(4 * level) << "" << root->info << endl;
		printTree(root->right, level + 1);
	}
	return;
}

//Функция получает на вход корень(ветвь) дерева, сумму, а так же массив, в который записывается сумма предков каждой из вершин
void sumOfPredoks(TreeNode* root, vector<int> & sums, int sum)
{
	if (root) {	
		if(root->left) {
			sum += root->info;
			sumOfPredoks(root->left, sums, sum);
			sum -= root->info;
		}
		if (root->right) {
			sum += root->info;
			sumOfPredoks(root->right, sums, sum);
			sum -= root->info;
		}
		if (!root->left && !root->right) {
			sums.push_back(sum);
		}
	}
}

void printSum(vector<int> sums) {
	for (int i = 0; i < sums.size(); i++)
	{
		cout << "Сумма предков " << i << "-ой вершина дерева = " << sums[i] << endl;
	}
}

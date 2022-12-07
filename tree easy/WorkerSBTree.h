#pragma once
#include "Worker.h"
#include <list>
class WorkerSBTree
{
private:
	struct WorkerNode {
		Worker worker;
		WorkerNode* left, * right;

		WorkerNode(Worker worker, WorkerNode* left, WorkerNode* right) {
			this->worker = worker;
			this->left = left;
			this->right = right;
		}
		WorkerNode() {
			this->worker = worker;
			this->left = nullptr;
			this->right = nullptr;
		}
	};
	int maxIdP = 1;
	WorkerNode* root; // Корень бинарного дерева поиска
public:
	WorkerSBTree();
	~WorkerSBTree();

	bool insert(Worker& worker, string key);

	bool insertWorker(WorkerNode*& root, Worker& worker, string key);

	Worker& search(string key, int value);

	void newBase(WorkerSBTree& tabelBase);

	void newBaseByTabelNum(WorkerNode*& root ,WorkerSBTree& tabelBase);

	// Рекурсивная функция поиска в дереве с корнем root вершины с ключом key
	bool searchWorker(WorkerNode*& root, string key, int value, Worker& worker);

	void searchList(int value, list<Worker*>& workers);

	void searchSalaries(WorkerNode*& root, int value, list<Worker*>& workers);

	// Удаление в дереве вершины по ключу key 
	// Возвращает 
	//   true в случае успешного удаления вершины;
	//   false, если вершина дерева с таким ключом в дереве отсутствует.	
	bool  erase(int key);

	// Рекурсивная функция поиска и удаления в дереве с корнем root вершины с ключом key
	bool  eraseWorker(WorkerNode*& root, int key);

	// Вспомогательная функция удаления вершины из БДП. 
	//Применяется в случае удаления вершины с двумя поддеревьями
	void  del(WorkerNode*& r, WorkerNode*& delnode);

	// Очистка бинарного дерева 
	void clear();

	// Рекурсивная функция очистки дерева с корнем root
	void clearSBTree(WorkerNode* root);

	friend ostream& operator<<(ostream& cout, WorkerSBTree& workerSBTree);

	ostream& print(ostream& cout, WorkerNode* root);
};


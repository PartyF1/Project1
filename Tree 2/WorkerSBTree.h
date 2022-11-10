#pragma once
#include "Worker.h"
class WorkerSBTree
{
private:
	struct WorkerNode {
		Worker worker;
		WorkerNode* left, * right;
		int num;
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

	WorkerNode* root; // Корень бинарного дерева поиска
public:
	WorkerSBTree();
	~WorkerSBTree();

	bool insert(Worker& worker, Key key);

	bool insertWorker(WorkerNode*& root, Worker& worker, Key key, int num);

	Worker& search(Key key);

	// Рекурсивная функция поиска в дереве с корнем root вершины с ключом key
	bool searchWorker(WorkerNode*& root, Key key, Worker & worker);

	// Удаление в дереве вершины по ключу key 
	// Возвращает 
	//   true в случае успешного удаления вершины;
	//   false, если вершина дерева с таким ключом в дереве отсутствует.	
	bool  erase(Key key);

	// Рекурсивная функция поиска и удаления в дереве с корнем root вершины с ключом key
	bool  eraseWorker(WorkerNode*& root, Key key);

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


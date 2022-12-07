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
	WorkerNode* root; // ������ ��������� ������ ������
public:
	WorkerSBTree();
	~WorkerSBTree();

	bool insert(Worker& worker, string key);

	bool insertWorker(WorkerNode*& root, Worker& worker, string key);

	Worker& search(string key, int value);

	void newBase(WorkerSBTree& tabelBase);

	void newBaseByTabelNum(WorkerNode*& root ,WorkerSBTree& tabelBase);

	// ����������� ������� ������ � ������ � ������ root ������� � ������ key
	bool searchWorker(WorkerNode*& root, string key, int value, Worker& worker);

	void searchList(int value, list<Worker*>& workers);

	void searchSalaries(WorkerNode*& root, int value, list<Worker*>& workers);

	// �������� � ������ ������� �� ����� key 
	// ���������� 
	//   true � ������ ��������� �������� �������;
	//   false, ���� ������� ������ � ����� ������ � ������ �����������.	
	bool  erase(int key);

	// ����������� ������� ������ � �������� � ������ � ������ root ������� � ������ key
	bool  eraseWorker(WorkerNode*& root, int key);

	// ��������������� ������� �������� ������� �� ���. 
	//����������� � ������ �������� ������� � ����� ������������
	void  del(WorkerNode*& r, WorkerNode*& delnode);

	// ������� ��������� ������ 
	void clear();

	// ����������� ������� ������� ������ � ������ root
	void clearSBTree(WorkerNode* root);

	friend ostream& operator<<(ostream& cout, WorkerSBTree& workerSBTree);

	ostream& print(ostream& cout, WorkerNode* root);
};


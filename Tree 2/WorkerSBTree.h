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

	WorkerNode* root; // ������ ��������� ������ ������
public:
	WorkerSBTree();
	~WorkerSBTree();

	bool insert(Worker& worker, Key key);

	bool insertWorker(WorkerNode*& root, Worker& worker, Key key, int num);

	Worker& search(Key key);

	// ����������� ������� ������ � ������ � ������ root ������� � ������ key
	bool searchWorker(WorkerNode*& root, Key key, Worker & worker);

	// �������� � ������ ������� �� ����� key 
	// ���������� 
	//   true � ������ ��������� �������� �������;
	//   false, ���� ������� ������ � ����� ������ � ������ �����������.	
	bool  erase(Key key);

	// ����������� ������� ������ � �������� � ������ � ������ root ������� � ������ key
	bool  eraseWorker(WorkerNode*& root, Key key);

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


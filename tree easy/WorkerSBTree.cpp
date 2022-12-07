#include "WorkerSBTree.h"
#include <iostream>

WorkerSBTree::WorkerSBTree()
{
	root = nullptr;
}


WorkerSBTree::~WorkerSBTree()
{
	clear();
}

bool WorkerSBTree::insert(Worker& worker, string key)
{
	return insertWorker(root, worker, key);
}

bool WorkerSBTree::insertWorker(WorkerNode*& root, Worker& worker, string key)
{
	if (root == nullptr)
	{
		worker.setIdP(this->maxIdP);
		this->maxIdP++;
		root = new WorkerNode(worker, nullptr, nullptr);
		return true;
	}
	else
	{
		if (worker.get(key) >= root->worker.get(key)) {
			return insertWorker(root->left, worker, key);
		}
		else if (worker.get(key) <= root->worker.get(key)) {
			return insertWorker(root->right, worker, key);
		}
		else {
			return false;
		}
	}
}

Worker& WorkerSBTree::search(string key, int value)
{
	Worker a;
	searchWorker(root, key, value, a);
	return a;
}

void WorkerSBTree::newBase(WorkerSBTree& tabelBase) {
	return newBaseByTabelNum(root, tabelBase);
}

void WorkerSBTree::newBaseByTabelNum(WorkerNode*& root ,WorkerSBTree& tabelBase) {
	if (root != nullptr) {
		tabelBase.insert(root->worker, "tabelNum");
		newBaseByTabelNum(root->left, tabelBase);
		newBaseByTabelNum(root->right, tabelBase);
	}
}

bool WorkerSBTree::searchWorker(WorkerNode*& root, string key, int value,  Worker& worker)
{
	if (root != nullptr)
	{
		if (root->worker.get(key) == value)
		{
			worker = root->worker;
			return true;
		}
		else
			if (value < root->worker.get(key))
				searchWorker(root->left, key, value, worker);
			else
				searchWorker(root->right, key, value, worker);
	}
	return false;
}

void WorkerSBTree::searchList(int value, list<Worker*>& workers) {
	searchSalaries(root, value, workers);
}

void WorkerSBTree::searchSalaries(WorkerNode*& root, int value, list<Worker*>& workers)
{
	if (root != nullptr)
	{
		if (root->worker.get("tabelNum") == value)
		{
			workers.push_back(new Worker(root->worker));
			searchSalaries(root->left, value, workers);
		}
		else
			searchSalaries(root->left, value, workers);
			searchSalaries(root->right, value, workers);
	}
}

void  WorkerSBTree::del(WorkerNode*& r, WorkerNode*& delnode)
{
	if (r->right)
		del(r->right, delnode);
	else
	{
		delnode->worker = r->worker;
		delnode = r;
		r = r->left;
	}
	return;
}

void WorkerSBTree::clear()
{
	clearSBTree(root);
	root = nullptr;
	return;
}

void WorkerSBTree::clearSBTree(WorkerNode* root)
{
	if (root != nullptr)
	{
		clearSBTree(root->left);
		clearSBTree(root->right);
		delete root;
	}
	return;
}

bool WorkerSBTree::erase(int key)
{
	return eraseWorker(root, key);
}

bool WorkerSBTree::eraseWorker(WorkerNode*& root, int key)
{
	//void DeleteNode(TreeNode * &p, int k)
	{
		WorkerNode* delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (key < root->worker.get("idP"))
				return eraseWorker(root->left, key);
			else
				if (key > root->worker.get("idP"))
					return eraseWorker(root->right, key);
				else
				{
					delnode = root;
					if (delnode->right == nullptr)
						root = delnode->left;
					else
						if (delnode->left == nullptr)
							root = delnode->right;
						else
							del(delnode->left, delnode);
					delete delnode;
					return true;
				}
		}
	}
}


ostream& WorkerSBTree::print(ostream& cout, WorkerNode* root)
{
	if (root)
	{
		print(cout, root->left);
		cout << root->worker << endl;
		print(cout, root->right);
	}
	return cout;
}

ostream& operator<<(ostream& cout, WorkerSBTree& workerSBTree)
{
	cout << "--------------------------------------------" << endl;
	return 	workerSBTree.print(cout, workerSBTree.root)
		<< "--------------------------------------------" << endl;

}
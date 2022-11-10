#include "WorkerSBTree.h"

WorkerSBTree::WorkerSBTree()
{
	root = nullptr;
}


WorkerSBTree::~WorkerSBTree()
{
	clear();
}

bool WorkerSBTree::insert(Worker& worker, Key key)
{
	int num = 1;
	return insertWorker(root, worker, key, num);
}

bool WorkerSBTree::insertWorker(WorkerNode*& root, Worker& worker, Key key, int num)
{
	if (root == nullptr)
	{
		root = new WorkerNode(worker, nullptr, nullptr);
		return true;
	}
	else
	{		
		
		if (!key.uniq) {
			worker.setIdP(num);
			if (worker.get(key) == root->worker.get(key)) {
				return insertWorker(root->left, worker, key, num);
			}
			else
				if (worker.get(key) > root->worker.get(key)) {
					return insertWorker(root->left, worker, key, num);
				}
				else if (worker.get(key) < root->worker.get(key)) {
					return insertWorker(root->right, worker, key, num);
				}
				else {
					
					return false;
				}
			
		}			
		else {
			worker.setIdP();
			if (worker.get(key) < root->worker.get(key)) {
				return insertWorker(root->left, worker, key, num);
			}
			else
				if (worker.get(key) > root->worker.get(key)) {
					return insertWorker(root->right, worker, key, num);
				}
				else
					return false;
			
		}		
	}
}

Worker& WorkerSBTree::search(Key key)
{	
	Worker a;
	searchWorker(root, key, a);
	return a;
}

bool WorkerSBTree::searchWorker(WorkerNode*& root, Key key, Worker & worker)
{	
	if (root != nullptr)
	{
		if (root->worker.get(key) == key.value)
		{
			worker = root->worker;
			return true;
		}
		else
			if (key.value < root->worker.get(key))
				searchWorker(root->left, key, worker);
			else
				searchWorker(root->right, key, worker);
	}
	return false;
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

bool WorkerSBTree::erase(Key key)
{
	return eraseWorker(root, key);
}

bool WorkerSBTree::eraseWorker(WorkerNode*& root, Key key)
{
	//void DeleteNode(TreeNode * &p, int k)
	{
		WorkerNode* delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (key.value < root->worker.get(key))
				return eraseWorker(root->left, key);
			else
				if (key.value > root->worker.get(key))
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
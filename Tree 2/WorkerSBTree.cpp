#include "WorkerSBTree.h"

WorkerSBTree::WorkerSBTree()
{
	root = nullptr;
}


WorkerSBTree::~WorkerSBTree()
{
	clear();
}

bool WorkerSBTree::insert(Worker& worker)
{
	return insertWorker(root, worker);
}

bool WorkerSBTree::insertWorker(WorkerNode*& root, Worker& worker)
{
	if (root == nullptr)
	{
		root = new WorkerNode(worker, nullptr, nullptr);
		return true;
	}
	else
	{
		if (worker.get("idP") < root->worker.get("idP"))
			return insertWorker(root->left, worker);
		else
			if (worker.get("idP") > root->worker.get("idP"))
				return insertWorker(root->right, worker);
			else
				return false;
	}
}

Worker& WorkerSBTree::search(Key key)
{	
	return searchWorker(root, key);
}

Worker& WorkerSBTree::searchWorker(WorkerNode*& root, Key key)
{	
	if (root != nullptr)
	{
		if (root->worker.get(key) == key.value)
		{
			return root->worker;
		}
		else
			if (key.value < root->worker.get(key))
				searchWorker(root->left, key);
			else
				searchWorker(root->right, key);
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
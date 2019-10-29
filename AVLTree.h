
#pragma once
class AVLTree
{
private:
	struct STree
	{
		int node;
		int height;
		STree* left;
		STree* right;
	};
public:
	STree* Tree;
	
	AVLTree() : Tree(nullptr) {};

	void addNode(STree*& tree, int item);

	int calcHeight(STree*& tree);

	int getHeight(STree*& tree);

	int getBalance(STree*& tree);
	
	STree * leftRotate(STree*& tree);

	STree * rightRotate(STree*& tree);

	STree * leftrightRotate(STree*& tree);

	STree * rightleftRotate(STree*& tree);

	STree * findeMin(STree*& tree);

	STree * removeMin(STree*& tree);

	STree * nodeBalanced(STree*& tree);
	
	void outTree(STree*& Tree);

	void findeNode(STree*& Tree, int item);
	
	void delNode(STree*& Tree, int item);

	~AVLTree();
};


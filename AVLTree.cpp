#include "AVLTree.h"

#include "stdIncl.h"

void AVLTree::addNode(STree *& tree, int item)
{
	if (tree== nullptr)
	{
		tree= new(STree);
		tree->left = tree->right = nullptr;

		tree->node = item;
		tree->height = 0;
	}
	else
	{
		if (item == tree->node)
		{

		}
		else
		{
			if (item < tree->node)
			{
				addNode(tree->left, item);
			}
			else
			{
				addNode(tree->right, item);
			}

			tree->height = calcHeight(tree);
			
			nodeBalanced(tree);
		}
	}
}

int AVLTree::calcHeight(STree *& tree)
{
	int l, r;

	l = getHeight(tree->left);

	r = getHeight(tree->right);
		
	return  ((l > r) ? l : r) + 1;
}

int AVLTree::getHeight(STree *& tree)
{
	return (tree != nullptr) ? tree->height : -1;
}

int AVLTree::getBalance(STree *& tree)
{
	return getHeight(tree->left) - getHeight(tree->right);
}

AVLTree::STree * AVLTree::rightRotate(STree *& tree)
{
	//Right Rotate;
	STree* tmpLeft;

	tmpLeft = tree->left;
	tree->left = tmpLeft->right;
	tmpLeft->right = tree;

	tree->height = calcHeight(tree);
	tmpLeft->height = calcHeight(tmpLeft);

	tree = tmpLeft;
	return tree;
}

AVLTree::STree * AVLTree::leftRotate(STree *& tree)
{
	//Right Rotate;
	STree* tmpRight;

	tmpRight = tree->right;
	tree->right = tmpRight->left;
	tmpRight->left = tree;


	tree->height = calcHeight(tree);
	tmpRight->height = calcHeight(tmpRight);

	tree = tmpRight;
	return tree;
}


AVLTree::STree * AVLTree::leftrightRotate(STree *& tree)
{
	tree->left = leftRotate(tree->left);
	return rightRotate(tree);
}

AVLTree::STree * AVLTree::rightleftRotate(STree *& tree)
{
	tree->right = rightRotate(tree->right);
	return leftRotate(tree);
}

AVLTree::STree * AVLTree::nodeBalanced(STree *& tree)
{
	tree->height = calcHeight(tree);
	if (getBalance(tree) == 2)
	{
		if (getBalance(tree->left) == 1)
		{
			//Right Rotate;
			tree = rightRotate(tree);
		}
		else
		{
			tree = leftrightRotate(tree);
		}
	}
	else
	{
		if (getBalance(tree) == -2)
		{
			if (getBalance(tree->right) == -1)
			{
				//Left Rotate;
				tree = leftRotate(tree);
			}
			else
			{
				tree = rightleftRotate(tree);
			}
		}
	}

	return tree;
}

void AVLTree::outTree(STree *& Tree)
{
	cout << Tree->node << ": " << Tree->height << endl;
	
	if (Tree->left != nullptr)
	{
		outTree(Tree->left);
	}
	

	if (Tree->right != nullptr)
	{
		outTree(Tree->right);
	}

}

void AVLTree::findeNode(STree *& Tree, int item)
{
	if (Tree != nullptr)
	{
		if ((Tree->node == item))
		{
			cout << "___________" << endl;
			cout << Tree->node << endl;
		}
		else
		{
			if (item < Tree->node)
			{
				findeNode(Tree->left, item);
			}
			else
			{
				findeNode(Tree->right, item);
			}
		}
	}
}

AVLTree::STree * AVLTree::findeMin(STree *& tree)
{
	return tree->left ? findeMin(tree->left) : tree;
}

AVLTree::STree * AVLTree::removeMin(STree *& tree)
{
	if (tree->left == nullptr)
	{
		return tree->right;
	}

	tree->left = removeMin(tree->left);
	return nodeBalanced(tree);
}

void  AVLTree::delNode(STree *& tree, int item)
{
	if (tree != nullptr)
	{
		if (item < tree->node)
		{
			delNode(tree->left, item);

		}
		else
		{
			if (item > tree->node)
			{
				delNode(tree->right, item);

			}
			else
			{
				//no childrens
				if ((tree->left == nullptr) && (tree->right == nullptr))
				{
					tree = nullptr;
				}
				else
				{
					// 1 childe
					if (tree->right == nullptr)
					{
						tree = tree->left;

					}
					else
					{
						if (tree->left == nullptr)
						{
							tree = tree->right;

						}
						else
						{
							// 2 childs
							STree * r = tree->right;
							STree * l = tree->left;
							STree * minL = findeMin(r);
							minL->right = removeMin(r);
							minL->left = l;
							tree = minL;

							nodeBalanced(tree);
						}
					}
				}
			}
		}
	}
	if (tree != nullptr)
	{
		nodeBalanced(tree);
	}
}

AVLTree::~AVLTree()
{
}

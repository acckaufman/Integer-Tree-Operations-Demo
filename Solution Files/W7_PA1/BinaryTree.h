#pragma once

template <class T>
class BinaryTree
{
private:
	//Structure for tree node, containing data and pointers to left and right child nodes.
	struct TreeNode
	{
		T value;			//The content of the node, the data
		TreeNode *left;		//Pointer to left child node
		TreeNode *right;	//Pointer to right child node
	};

	TreeNode *root;			//Pointer to root node

	//Private member functions

	//###########################################################################
	//Function that accepts a parameter nodePtr which points to a tree into		#
	//which the parameter newNode will be inserted.								#
	//*Note: recursive function.*												#
	//###########################################################################
	void insert(TreeNode *&nodePtr, TreeNode *&newNode)
	{
		//If the tree is empty, assign newNode as the root.
		if (nodePtr == nullptr)
			nodePtr = newNode;

		//If the value in the new node is less than the value contained in nodePtr, move down the left branch (recursively).
		else if (newNode->value < nodePtr->value)
			insert(nodePtr->left, newNode);

		//If the value in the new node is greater than the value contained in nodePtr, move down the right branch (recursively).
		else
			insert(nodePtr->right, newNode);
	}

	//###########################################################################
	//Deletes all nodes in the tree (used by destructor).						#
	//###########################################################################
	void destroySubTree(TreeNode *nodePtr)
	{
		//If nodePtr exists, recursively delete its child nodes using this function, then delete this node (nodePtr).
		if (nodePtr)
		{
			if (nodePtr->left)
				destroySubTree(nodePtr->left);		//If the left child exists, move on and delete it.
			if (nodePtr->right)
				destroySubTree(nodePtr->right);		//Same for right child.

			delete nodePtr;							//Now delete this node.
		}
	}

	//###########################################################################
	//Deletes the node whose value matches the parameter.						#
	//###########################################################################
	void deleteNode(T val, TreeNode *&nodePtr)
	{
		if (val < nodePtr->value)
			deleteNode(val, nodePtr->left);
		else if (val > nodePtr->value)
			deleteNode(val, nodePtr->right);
		else
			makeDeletion(nodePtr);
	}

	//###########################################################################
	//Accepts parameter of a reference to a pointer to the node that is to be	#
	//deleted.  Removes the node and reattaches the child branches.				#
	//###########################################################################
	void makeDeletion(TreeNode *&nodePtr)
	{
		//Define a temporary pointer to use for reattaching the left subtree.
		TreeNode *tempNodePtr = nullptr;

		//If the node does not exist
		if (nodePtr == nullptr)
			cout << "Cannot delete empty node." << endl;

		//If the node only has a left child
		else if (nodePtr->right == nullptr)
		{
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->left;		//Reattach the left child
			delete tempNodePtr;
		}

		//If the node only has a right child
		else if (nodePtr->left == nullptr)
		{
			tempNodePtr = nodePtr;
			nodePtr = nodePtr->right;		//Reattach the right child
			delete tempNodePtr;
		}

		//If the node has two children
		else
		{
			tempNodePtr = nodePtr->right;			//Move one node to the right.
			while (tempNodePtr->left)
				tempNodePtr = tempNodePtr->left;	//Find the end left node.
			tempNodePtr->left = nodePtr->left;
			tempNodePtr = nodePtr;					//Reattach the left subtree.
			nodePtr = nodePtr->right;				//Reattach the right subtree.
			delete tempNodePtr;						//Delete the desired node.
		}
	}

	//###########################################################################
	//Displays the values in the tree using inorder traversal.					#
	//###########################################################################
	void displayInOrder(TreeNode *nodePtr) const
	{
		if (nodePtr)
		{
			displayInOrder(nodePtr->left);
			cout << nodePtr->value << endl;
			displayInOrder(nodePtr->right);
		}
	}

	//###########################################################################
	//Displays the values in the tree using preorder traversal.					#
	//###########################################################################
	void displayPreOrder(TreeNode *nodePtr) const
	{
		if (nodePtr)
		{
			cout << nodePtr->value << endl;
			displayPreOrder(nodePtr->left);
			displayPreOrder(nodePtr->right);
		}
	}

	//###########################################################################
	//Displays the values in the tree using postorder traversal.				#
	//###########################################################################
	void displayPostOrder(TreeNode *nodePtr) const
	{
		if (nodePtr)
		{
			displayPostOrder(nodePtr->left);
			displayPostOrder(nodePtr->right);
			cout << nodePtr->value << endl;
		}
	}

	//###########################################################################
	//Count the number of nodes in the tree using a recursive function.			#
	//###########################################################################
	int countNodes(TreeNode *nodePtr)
	{
		//If the node has no children
		if (nodePtr->left == nullptr && nodePtr->right == nullptr)
			return 1;

		//If the node has only a left child
		else if (nodePtr->left != nullptr && nodePtr->right == nullptr)
			return (1 + countNodes(nodePtr->left));

		//If the node has only a right child
		else if (nodePtr->left == nullptr && nodePtr->right != nullptr)
			return (1 + countNodes(nodePtr->right));

		//If the node has a left and right child
		else
			return (1 + countNodes(nodePtr->left) + countNodes(nodePtr->right));
	}

	//###########################################################################
	//Count the number of leaf nodes in the tree using a recursive function.	#
	//###########################################################################
	int countLeaves(TreeNode *nodePtr)
	{
		//Only return a count if the node has no children.
		if (nodePtr->left == nullptr && nodePtr->right == nullptr)
			return 1;

		//Otherwise, keep traversing the tree until a leaf node is found.

		//If the node has only a left child
		else if (nodePtr->left != nullptr && nodePtr->right == nullptr)
			return countLeaves(nodePtr->left);

		//If the node has only a right child
		else if (nodePtr->left == nullptr && nodePtr->right != nullptr)
			return countLeaves(nodePtr->right);

		//If the node has a left and right child
		else
			return (countLeaves(nodePtr->left) + countLeaves(nodePtr->right));
	}

	//###########################################################################
	//Determine the maximum height of the tree (the length of the longest		#
	//branch, in other words, the number of levels it has).						#
	//###########################################################################
	int findHeight(TreeNode *nodePtr)
	{
		//If the subtree is empty, return 0.
		if (!nodePtr)
			return 0;

		//Otherwise, find the height of the tree.

		//Define variables to hold the height of the left and right subtrees.
		int leftHeight = findHeight(nodePtr->left);
		int rightHeight = findHeight(nodePtr->right);

		//Determine which of the two is larger.

		//If nodePtr->right points to NULL, then 0 will be returned (see base case).
		//In this case, leftHeight will be greater, so we return 1 (for the current node) plus leftHeight.
		if (leftHeight > rightHeight)
			return (leftHeight + 1);

		//Otherwise, return 1 (for the current node) plus rightHeight, which is either greater than or equal to leftHeight.
		else
			return (rightHeight + 1);
	}

public:
	//###########################################################################
	//Constructor. Sets root to nullptr.										#
	//###########################################################################
	BinaryTree()
	{
		root = nullptr;
	}

	//###########################################################################
	//Destructor. Deletes all tree nodes.										#
	//###########################################################################
	~BinaryTree()
	{
		destroySubTree(root);
	}

	//Binary tree operations

	//###########################################################################
	//Function that creates a new node in which to store data, and passes that	#
	//node to the insert() function (private member function, defined above).	#
	//###########################################################################
	void insertNode(T val)
	{
		//Create a new node
		TreeNode *newNode = nullptr;

		//Dynamically allocate memory for a new node and store val in it
		newNode = new TreeNode;
		newNode->value = val;

		//Point left and right child node pointers to nullptr
		newNode->left = newNode->right = nullptr;

		//Insert the new node into the tree
		insert(root, newNode);
	}

	//###########################################################################
	//Searches for a value within the tree.  Returns true if the value is		#
	//found, and false if it is not.											#
	//###########################################################################
	bool searchNode(T searchItem)
	{
		TreeNode *nodePtr = root;		//Start traversing at the top of the tree

		while (nodePtr)
		{
			if (nodePtr->value == searchItem)
				return true;						//Stop traversing as soon as the value is found and return true.
			else if (searchItem < nodePtr->value)
				nodePtr = nodePtr->left;
			else
				nodePtr = nodePtr->right;
		}
		
		//If the while loop finishes executing without returning true, this means the value was not found.
		return false;
	}

	//###########################################################################
	//Deletes the node whose value member is the same as the item passed as a	#
	//parameter by calling deleteNode() (private member function).				#
	//###########################################################################
	void remove(T val)
	{
		deleteNode(val, root);
	}

	//###########################################################################
	//Displays the nodes in inOrder format.										#
	//###########################################################################
	void displayInOrder() const
	{
		displayInOrder(root);
	}

	//###########################################################################
	//Displays the nodes in preOrder format.									#
	//###########################################################################
	void displayPreOrder() const
	{
		displayPreOrder(root);
	}

	//###########################################################################
	//Displays the nodes in postOrder format.									#
	//###########################################################################
	void displayPostOrder() const
	{
		displayPostOrder(root);
	}
	
	//###########################################################################
	//Returns the total nodes in the tree.										#
	//###########################################################################
	int totalNodes()
	{
		return countNodes(root);
	}

	//###########################################################################
	//Returns the number of leaf nodes in the tree.								#
	//###########################################################################
	int leafNodes()
	{
		return countLeaves(root);
	}

	//###########################################################################
	//Returns the length of the tree's longest branch.							#
	//###########################################################################
	int treeHeight()
	{
		return findHeight(root);
	}
};


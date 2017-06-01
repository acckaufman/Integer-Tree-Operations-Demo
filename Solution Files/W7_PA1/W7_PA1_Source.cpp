//This program demonstrates operations on a binary tree.
#include <iostream>
#include "BinaryTree.h"
using namespace std;

int main()
{
	//Let's keep it simple and try our binary tree operations using integers.
	cout << "Now creating a tree of ints.  Adding the following values, in this order: 5, 8, 21, 3, 45, 34, 1, 6, 15, 27, 33, 40.";
	cout << endl << endl;
	BinaryTree<int> integerTree;
	integerTree.insertNode(5);
	integerTree.insertNode(8);
	integerTree.insertNode(21);
	integerTree.insertNode(3);
	integerTree.insertNode(45);
	integerTree.insertNode(34);
	integerTree.insertNode(1);
	integerTree.insertNode(6);
	integerTree.insertNode(15);
	integerTree.insertNode(27);
	integerTree.insertNode(33);
	integerTree.insertNode(40);

	system("pause");

	cout << endl;
	cout << "Let's check out our tree." << endl << endl;
	cout << "Display the tree using the inOrder function:" << endl;
	integerTree.displayInOrder();
	cout << endl;

	system("pause");

	cout << endl;
	cout << "Display the tree using the preOrder function:" << endl;
	integerTree.displayPreOrder();
	cout << endl;

	system("pause");

	cout << endl;
	cout << "Display the tree using the postOrder function:" << endl;
	integerTree.displayPostOrder();
	cout << endl;

	system("pause");
	
	cout << endl;
	cout << "Let's search the tree for the value 6." << endl;

	bool found;
	found = integerTree.searchNode(6);
	if (found)
		cout << "The value 6 was found." << endl << endl;
	else
		cout << "The value 6 was not found." << endl << endl;

	system("pause");

	cout << endl;
	cout << "Let's search the tree for the value 9." << endl;

	found = integerTree.searchNode(9);
	if (found)
		cout << "The value 9 was found." << endl << endl;
	else
		cout << "The value 9 was not found." << endl << endl;

	system("pause");

	cout << endl;
	cout << "Let's try deleting a couple nodes." << endl << endl;
	cout << "Here are the current nodes of our tree, in order:" << endl;
	integerTree.displayInOrder();
	cout << endl;

	system("pause");

	cout << endl;
	cout << "Now deleting the node 34." << endl;
	integerTree.remove(34);
	cout << "Done." << endl << endl;
	cout << "Here are the current nodes of our tree, in order:" << endl;
	integerTree.displayInOrder();
	cout << endl;

	system("pause");

	cout << endl;
	cout << "Now deleting the node 8." << endl;
	integerTree.remove(8);
	cout << "Done." << endl << endl;
	cout << "Here are the current nodes of our tree, in order:" << endl;
	integerTree.displayInOrder();
	cout << endl;

	system("pause");

	cout << endl;
	cout << "Finally, let's determine the number of tree nodes the number" << endl
		<< "of leaf nodes, and the max height of the tree." << endl << endl;
	int nodes = integerTree.totalNodes();
	int leaves = integerTree.leafNodes();
	int height = integerTree.treeHeight();

	cout << "Three tree has " << nodes << " total nodes, " << leaves << " leaf nodes," << endl
		<< "and the longest branch is " << height << " nodes long." << endl << endl;

	system("pause");
	return 0;
}
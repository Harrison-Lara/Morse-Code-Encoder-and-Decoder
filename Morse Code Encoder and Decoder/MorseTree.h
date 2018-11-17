#pragma once
#include "BinaryTree.h"
#include <string>
#include <fstream>
using namespace std;

class MorseTree : public Binary_Tree {

private:


public:

	MorseTree() {
		Binary_Tree();
	}

	//assemble tree by adding values to left or right tree
	void addValue(BTNode *&node, string code, string value) {

		if (node == NULL) {
			node = new BTNode();
		}
		if (code.size() == 0) {
			node->data = value;
		}
		else if (code[0] == '.') {
			addValue(node->left, code.substr(1), value);
		}
		else if (code[0] == '_') {
			addValue(node->right, code.substr(1), value);
		}
	}
};
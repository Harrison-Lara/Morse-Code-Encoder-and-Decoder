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

	void add_letter(BTNode *&node, string code, string letter) {

		if (node == NULL) {
			node = new BTNode();
		}
		if (code.size() == 0) {
			node->data = letter;
		}
		else if (code[0] == '.') {
			add_letter(node->left, code.substr(1), letter);
		}
		else if (code[0] == '_') {
			add_letter(node->right, code.substr(1), letter);
		}
	}
};
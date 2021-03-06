#pragma once
#include <string>
using namespace std;

struct BTNode {
	
	string data;
	BTNode *left;
	BTNode *right;

	//Default constructor
	BTNode(string values = "", BTNode *value_left = NULL, BTNode *value_right = NULL) {
		data = values;
		left = value_left;
		right = value_right;
	}

	//Destructor
	~BTNode() {}
};

class Binary_Tree {

public:

	BTNode *node;

	Binary_Tree() {
		node = new BTNode();
	}

	Binary_Tree(BTNode *newnode) {
		node = newnode;
	}

	//assigning node to value for left and right nodes
	Binary_Tree(const string & values, const Binary_Tree & left = Binary_Tree(), const Binary_Tree & right = Binary_Tree()) {
		node = new BTNode(values, left.node, right.node);
	}

	//getter
	BTNode* get_root() {
		return node;
	}

	//setter
	void set_root(BTNode *data) {
		node = data;
	}

	//getters for left and right tree
	Binary_Tree get_left_subtree() {
		return Binary_Tree(node->left);
	}

	Binary_Tree get_right_subtree() {
		return Binary_Tree(node->right);
	}
};
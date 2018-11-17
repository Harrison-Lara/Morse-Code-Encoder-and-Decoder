#include "MorseTree.h"
#include "Hash Table.h"
#pragma once

class Converter {
private:

	MorseTree morse_tree;
	CodeHash morse_hash;

public:
	Converter() {
		morse_tree = MorseTree();
	}

	void parse();
	string search(BTNode *&node, string in);
	string decode(string in);
	string encode(string in);
};

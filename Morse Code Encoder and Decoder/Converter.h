#include "MorseTree.h"
#include "Hash Table.h"
#pragma once

class Converter {
private:

	MorseTree code_tree;
	CodeHash morse_hash;

public:

	Converter() {
		code_tree = MorseTree();
	}

	//parse and take input for encoding and decoding
	void parse();
	string search(BTNode *&node, string input);
	string decode(string input);
	string encode(string input);
};

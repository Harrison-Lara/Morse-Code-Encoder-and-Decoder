#include "Converter.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void Converter::parse() {

	//get file codes
	ifstream morse;
	morse.open("MorseCode.txt");
	string line = "";

	//uses file to learn how to create tree/nodes
	while (morse.good()) {
		morse >> line;
		string value = line.substr(0, 1);
		string code = line.substr(1);
		BTNode *morse_root = code_tree.get_root();

		//adding values to tree and hash table
		code_tree.addValue(morse_root, code, value);
		morse_hash.addValue(value, code);
	}
	morse.close();
}

//converter takes the nodes and searches the input
string Converter::search(BTNode *&node, string input) {

	if (node->data != "" && input.size() == 0) {
		return node->data;
	}
	else if (input.at(0) == '.') {
		return search(node->left, input.substr(1));
	}
	else if (input.at(0) == '_') {
		return search(node->right, input.substr(1));
	}
	else if (node == NULL) {
		return "";
	}
	else {
		return "Invalid Input";
	}
}

//converter takes the nodes and decodes the input
string Converter::decode(string input) {

	char key = ' ';
	string code = "";
	BTNode *node = code_tree.get_root();
	string result = "";

	for (int i = 0; i < input.size(); i++) {
		key = input[i];
		if (key != ' ') {
			code += key;
			if (i == input.size() - 1) {
				result += search(node, code);
			}
		}
		else if (key == ' ') {
			result += search(node, code);
			code = "";
		}
	}
	return result;
}

//converter takes the nodes and encodes the input
string Converter::encode(string input) {

	string result = "";
	string value;
	for (string::iterator iter = input.begin(); iter != input.end(); iter++) {
		value = *iter;
		result.append(morse_hash.type(value));
		result.append(" ");
	}
	return result;
}
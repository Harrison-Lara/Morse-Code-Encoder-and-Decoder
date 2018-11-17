#include "Converter.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void Converter::parse() {
	ifstream morse;
	morse.open("MorseCode.txt");
	string line = "";

	while (morse.good()) {
		morse >> line;
		string letter = line.substr(0, 1);
		string code = line.substr(1);
		BTNode *morse_root = morse_tree.get_root();
		morse_tree.add_letter(morse_root, code, letter);
		hash_table.add_letter(letter, code);
	}
	morse.close();
}

string Converter::search(BTNode *&node, string in) {
	if (node->data != "" && in.size() == 0) {
		return node->data;
	}
	else if (in.at(0) == '.') {
		return search(node->left, in.substr(1));
	}
	else if (in.at(0) == '_') {
		return search(node->right, in.substr(1));
	}
	else if (node == NULL) {
		return "";
	}
	else {
		return "Invalid morse string";
	}
}

string Converter::decode(string in) {
	char token = ' ';
	string code = "";
	BTNode *root = morse_tree.get_root();
	string result = "";

	for (int i = 0; i < in.size(); i++) {
		token = in[i];
		if (token != ' ') {
			code += token;
			if (i == in.size() - 1) {
				result += search(root, code);
			}
		}
		else if (token == ' ') {
			result += search(root, code);
			code = "";
		}
	}
	return result;
}

string Converter::encode(string in) {
	string result = "";
	string letter;
	for (string::iterator iter = in.begin(); iter != in.end(); iter++) {
		letter = *iter;
		result.append(hash_table.get_morse_version(letter));
		result.append(" ");
	}
	return result;
}
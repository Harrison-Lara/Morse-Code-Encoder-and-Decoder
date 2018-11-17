#pragma once
#include <string>
#include <unordered_map>
using namespace std;

class CodeHash {

private:
	
	//create value mapping for input
	unordered_map<string, string> map;

public:
	
	//assembling the hash table
	CodeHash() {}

	void addValue(string value, string code) {
		map[value] = code;
	};

	string type(string value) {
		return map[value];
	};
};
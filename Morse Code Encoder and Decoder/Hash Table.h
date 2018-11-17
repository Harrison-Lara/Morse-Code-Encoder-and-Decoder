#pragma once
#include <string>
#include <unordered_map>
using namespace std;

class CodeHash {

private:

	unordered_map<string, string> map;

public:

	CodeHash() {}

	void addValue(string value, string code) {
		map[value] = code;
	};

	string get_morse_version(string value) {
		return map[value];
	};
};
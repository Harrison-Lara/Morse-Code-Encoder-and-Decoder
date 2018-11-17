#include "Converter.h"
#include <iostream>
using namespace std;

void main() {

	Converter code;
	code.parse();
	string test = code.decode("_...");
	string test1 = code.encode("Computer Science");
	cout << test << "\n" << " " << test1 << endl;

}
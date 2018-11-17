#include "Converter.h"
#include <iostream>
using namespace std;

void main() {

	Converter code;
	code.parse();
	string test = code.decode("_..."); // change value for testing
	string test1 = code.encode("Computer Science"); //change value for testing
	cout << test << "\n" << " " << test1 << endl;

}
#include "Converter.h"
#include <iostream>
using namespace std;

void main() {

	Converter MC;
	MC.parse();
	string result1 = MC.decode("_...");
	string result2 = MC.encode("Computer Science");
	cout << result1 << "\n" << " " << result2 << endl;

}
/* Write a C++ programs that:

0a. Implement a program writing 1 million random integers with values 0 to 2^30-1 to a file "points.txt"
0b. Implement a program writing 10,000 random ranges in format "a:b" where a is 0 to 2^29-1 and b = a + (random 128 to 1024) to a file "ranges.txt"
*/

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>
#include <ctime>

using namespace std;

int main() {
	ofstream outFile("ranges.txt");
		if (!outFile) {
			cout << "Can't open file" << endl;
			return 1;
		}
	
	mt19937 gen(time(0));

	for (int i = 0; i < 10000; i++) {
		int a = gen() % (1 << 29);
		int b = a + 128 + (gen() % 1024);
		
		outFile << a << ":" << b << '\n';
	}
	
	outFile.close();
	cout << "ranges.txt file generated" << endl;
	
	return 0;
}

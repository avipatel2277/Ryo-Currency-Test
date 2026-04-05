/* Write a C++ programs that:

0a. Implement a program writing 1 million random integers with values 0 to 2^30-1 to a file "points.txt"
0b. Implement a program writing 10,000 random ranges in format "a:b" where a is 0 to 2^29-1 and b = a + (random 128 to 1024) to a file "ranges.txt"
*/

#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <cmath>
using namespace std;

int main() {
	ofstream outFile("points.txt");
		if (!outFile) {
			cout << "Can't open file" << endl;
			return 1;
		}
		
			
	random_device rd;
	mt19937 gen(rd());
	
	long long max_val_0a = pow(2,30)-1;
	uniform_int_distribution<long long> dist(0, max_val_0a);
	
	for (int i = 0; i < 1000000; i++) {
		outFile << dist(gen) << '\n';
	}
	
	
		outFile.close();
		cout << "points.txt file generated" << endl;

	return 0;
}
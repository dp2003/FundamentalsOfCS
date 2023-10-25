#include <iostream>
#include <fstream>
using namespace std;
int main() {
	fstream sample;
	sample.open("sample", ios::out);
	if (!sample) {
		cout << "File not created!";
	}
	else {
		cout << "File created successfully!";
		cout<<"Write operation successful";
		sample<<"Hello";
		sample.close();

	}


	return 0;
}

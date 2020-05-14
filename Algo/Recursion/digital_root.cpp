#include<iostream>
using namespace std;

int digital_root(int num) {
	if (num/10 == 0) {
		return num;
	}

	return digital_root(num%10 + digital_root(num/10));
}

// Digital Root for 191 = 1 + 9 + 1 = 11 = 1 + 1 = 2
int main() {

	int num = 191;
	cout << digital_root(num) << endl;
	return 0;
}
#include<iostream>
using namespace std;


int tower_of_hanoi_steps(int n) {
	if (n <= 1)
		return n;

	return 2*tower_of_hanoi_steps(n-1) + 1;
}

void tower_of_hanoi_algo(int n, int r1, int r2) {

	if (n == 2) {
		int leftR = 6 - r1 - r2;
		cout << "Move disk 1 from rod " + to_string(r1) + " to rod " + to_string(leftR) << endl;
		cout << "Move disk 2 from rod " +  to_string(r1) + " to rod " + to_string(r2) << endl;
		cout << "Move disk 1 from rod " + to_string(leftR) + " to rod " + to_string(r2) << endl;
		return;
	}

	tower_of_hanoi_algo(n-1, r1, 6-r1-r2);
	cout << "Move disk " + to_string(n) << " from rod " + to_string(r1) + " to rod " + to_string(r2)<< endl;
	tower_of_hanoi_algo(n-1, 6-r1-r2, r2);

}
 
int main() {
	int n = 4;
	cout << tower_of_hanoi_steps(n) << endl;
	tower_of_hanoi_algo(n, 1, 3);
}
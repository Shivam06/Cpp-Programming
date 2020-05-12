#include<iostream>
using namespace std;

string printNo(int num, int N) {
    if (num > N) {
        return "";
    }   
    
    return to_string(num) + " " + printNo(num+1, N);
}

int main() {
	cout << printNo(1, 10) << endl;
	return 0;
}
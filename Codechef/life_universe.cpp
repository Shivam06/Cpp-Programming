#include <iostream>
using namespace std;

int main() {
    
    int num;
    bool flag = false;
    while (cin>>num) {
        if (flag)
            continue;
        
        if (num == 42) {
            flag = true;
            continue;
        }
        
        cout << num << endl;
    }
	return 0;
}

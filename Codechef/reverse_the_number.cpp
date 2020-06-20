#include <iostream>
#include <cmath>
using namespace std;

int length(int num) {
    
    if (num == 0)
        return 1;
        
    int len = 0;
    while (num) {
        num = num/10;
        len++;
    }
    
    return len;
}

int reverse_num(int num) {
    int len = length(num);
    int output = 0;
    
    while (num) {
        int last = num%10;
        output += last*pow(10, len-1);
        len--;
        num/=10;
    }
    
    return output;
}

int main() {
	int T, num;
	
	cin>>T;
	for (int i = 0; i < T; i++) {
	    
	    cin>>num;
	    cout<<reverse_num(num) << endl;
	    
	}
	return 0;
}

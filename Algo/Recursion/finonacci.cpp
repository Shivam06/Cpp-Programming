#include<iostream>
using namespace std;

long long fibonacci(int n)
{
    if (n <= 1)
        return n;
        
    return fibonacci(n-1) + fibonacci(n-2);
}


int main() {

	int n = 20;
	cout << fibonacci(n) << endl;
}
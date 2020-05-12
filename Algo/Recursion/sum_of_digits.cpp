#include<iostream>
using namespace std;

int sumOfDigits(int n)
{
    if (n == 0)
        return 0;
    
    return n%10 + sumOfDigits(n/10);
}

int count_digits(int n) {
    return n==0? n: count_digits(n/10) + 1;
}

//Complete this function
int countDigits(int n)
{
   if (n == 0)
       return 1;
       
    return count_digits(n);
}

int main() {
	cout << sumOfDigits(49) << endl;
	cout << countDigits(49) << endl;
	cout << countDigits(0) << endl;
}
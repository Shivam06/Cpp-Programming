#include <iostream>
#include <vector>
using namespace std;

bool isDivisibleBy3(long long k, int f, int s) {

    f = f%10;
    s = s%10;
    int num = (f + s)%10;
    if (k <= 2) {
        return (f + s)%3==0;
    }
    long long sum = num + f + s;
    long long sum_of_2 = (f + s + num);
    long long sum_of_4 = 0;
    vector<int> v;
    
    int max = k-3 >= 4? 4: k-3; 
    for (int i = 0; i < max; i++) {
        num = (num*2)%10;
        v.push_back(num);
        sum += num;
        sum_of_4 += num;
    }
    
    if (k <= 7) {
        return sum%3 == 0;
    }
    
    
    sum = ((k-3)/4)*sum_of_4 + sum_of_2;
    
    int r = (k-3)%4;
    for (int j = 0; j < r; j++) {
        sum += v[j];
    }
    
    return sum%3 == 0;
}

int main() {
	int T;
	cin>>T;
	
	for (int i = 0; i < T; i++) {
	    int f, s;
	    long K;
	    cin>>K>>f>>s;
	    if (isDivisibleBy3(K, f, s)) {
	        cout << "YES" << endl;
	    } else {
	        cout << "NO" << endl;
	    }
	}
	
	return 0;
}

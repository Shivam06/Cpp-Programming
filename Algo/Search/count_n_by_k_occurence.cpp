#include "../../helper_functions.cpp"
#include<map>
// Given an array and element k, find number of elements with occurence greater
// than n/k.

int count_of_occurence(vi& v, int k) {
	map<int, int> M;
	int n = v.size();

    loop(i, v.size()) {
        M[v[i]] += 1;
    } 
    
    int count = 0;
    tr(M, itr) {
        if ((*itr).second > n/k)
            count++;
    }
    
    return count;

}

int main() {
	vi v{{2, 35, 35, 2, 4}};
	cout << count_of_occurence(v, 2) << endl;
}
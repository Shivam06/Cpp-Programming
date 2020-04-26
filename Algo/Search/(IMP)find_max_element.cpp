#include "../../helper_functions.cpp"

// Find an element in the array which occurs more than n/2 times.

// Optimal Solution - O(n) time and O(1) space.

// Algo used - Moore's Voting Algorithm.

int find_majority_candidate(vi& v) {
    int maj_idx = 0;
    int count = 1;
    
    loop(i, v.size()) {
        if (v[i] == v[maj_idx]) {
            count++;
            continue;
        } 
        
        count--;
        if (count == 0) {
            maj_idx = i;
            count = 1;
        }
    }
    return v[maj_idx];
}

bool isMajorityElement(vi& v, int num) {
    
    int count = 0;
    loop(i, v.size()) {
        if (v[i] == num) 
            count++;
    }
    
    return count > v.size()/2;
}

int majority_element(vi& v) {
	int num = find_majority_candidate(v);

	if (isMajorityElement(v, num))
		return num;

	return -1;
}

int main() {

	vi v{1,1,3,3,1};
	cout << majority_element(v) << endl;
	return 0;
}
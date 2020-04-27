#include "../../helper_functions.cpp"


// Given an array with [1-N] integers, with all elements occuring once but 2 elements occuring twice.
// Find the 2 repeated elements.

void two_repeated_elements(vi& v) {
	
	int n = v.size()-1;
	loop(i, v.size()) {
		//cout << "element is " <<v[i] << endl;
		int idx = v[i]%n - 1;
		//cout << "idx is " << idx << endl;
		v[idx] += n;
	}

	int first = -1, second = -1;
	loop(i,n) {
		if (v[i]/n > 1) {
			if (first == -1) {
			    first = i + 1;
			    continue;
			}
			if (second == -1) {
			    second = i + 1;
			    break;
			}
 		}
	}
	
	int first_c = 0, second_c = 0;
	loop(i,v.size()) {
		//cout << v[i]% n << endl;
	    if (v[i]%n == first) {
	        first_c++;
	        if (first_c == 2)
	            cout << first << " ";
	        continue;
	    } 
	    
	    if (v[i]%n == second) {
	        second_c++;
	        if (second_c == 2)
	            cout << second << " ";
	    }
	}
}

// This is the best approach.
void two_repeated_elements_2(vi& v) {
	int n = v.size();

	loop(i, n) {
		if (v[abs(v[i])] < 0)
			cout << abs(v[i]) << " ";
		else 
			v[v[i]]*=-1;
	}
}

int main() {
	vi v{{1, 1, 2, 2}};
	two_repeated_elements_2(v);
}
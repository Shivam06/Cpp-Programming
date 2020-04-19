#include "helper_functions.cpp"

void make_profit(vi& a) {
	
	int i = 0, n = a.size();
	bool bought = false;

	vii v;
	int k = 0;

	while (i < n-1) {

		if(a[i] == a[i+1]) {
			i++;
			continue;
		}

		if (a[i] > a[i+1]) {
			if (bought) {
				v[k++].second = i;
				bought = false;
			} 
			i++;
			continue;
		}

		if (a[i] < a[i+1]) {
			if (!bought) {
				pb(v, make_pair(i, 0));
				bought = true;
			} 
			i++;
			continue;
		}
	}

	if (v.empty()) {
		cout << "No Profit";
		return;
	}

	if (!v.empty() && v[k].second == 0) {
		v[k].second = n-1;
	}

	loop(i, v.size()) {
		cout << "("<< v[i].first<<" "<<v[i].second<<") "; 
	}
}


int main() {
	vi v{{5, 5, 5, 5, 5}};
	make_profit(v);
}

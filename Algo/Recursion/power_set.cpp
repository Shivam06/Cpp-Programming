#include<iostream>
#include<vector>
using namespace std;

void print(vector<string> v) {
	for (auto itr = v.begin(); itr != v.end(); itr++) {
		cout << *itr << " ";
	}
	cout << endl;
}

vector<string> powerSet(string s)
{   
    if (s.size() == 1) {
        vector<string> v{{"", s}};
        return v;
    }
    
    vector<string> tmp = powerSet(s.substr(0, s.size()-1));
    string t(1, s[s.size()-1]); // IMPORTANT

    //print(tmp);
    int size = tmp.size();
    for(int i = 0; i < size; i++) {
        tmp.push_back(tmp[i] + t);
    }

    //print(tmp);
    return tmp;
}

int main() {
	vector<string> v = powerSet("pqr");
	print(v);
}
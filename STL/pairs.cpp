#include<iostream>
#include<vector>
using namespace std;

int main() {

    // Basic initialization.
    vector< pair<string, pair<int,int> > > v;
    v.push_back(make_pair("shivam", make_pair(9,10)));
    v.push_back(make_pair("megha", make_pair(8,10)));

    for (int i = 0; i < v.size(); i++) {
        cout << "Candidate name: " << v[i].first << endl;
        cout << "Subject 1: " << v[i].second.first << endl;
        cout << "Subject 2: " << v[i].second.second << endl;
    }
}
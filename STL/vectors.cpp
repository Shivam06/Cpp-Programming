#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int i = 0;

void printVector(vector<int>& v) {

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl << endl;
}

void printVector(vector<vector<int> >& v) {

    int N = v.size();
    int M = v[0].size();
    cout << "Vector shape: " << N << " X " << M << endl;

    for (int i = 0; i < N; i++) {
        printVector(v[i]);
    }

}

int main() {

    // Basic Initialization.
    // Once initialized, it has 3 elements, valued 0. 
    cout << " Test : " << ++i << endl;
    vector<int> v(3); 
    v.push_back(3);
    v.push_back(5);
    printVector(v);

    // Will remove all the elements of the vector.
    cout << " Test : " << ++i << endl;
    v.clear();  
    printVector(v);

    // Initialize with default value.
    cout << " Test : " << ++i << endl;
    vector<int> v2(3, 2); 
    printVector(v2);

    // Multidimensional vectors
    cout << " Test : " << ++i << endl;
    int N = 3, M = 2;
    vector<vector<int> > matrix(N, vector<int>(M, -1));

    printVector(matrix);

    // Vector manipulation
    v.push_back(3);
    v.push_back(5);
    v.insert(v.begin()+1, 2);
    printVector(v);

    v.erase(v.begin(),v.begin()+2);
    printVector(v);
    
}


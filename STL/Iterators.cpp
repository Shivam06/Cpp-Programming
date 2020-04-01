#include<iostream>
#include<vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define tr(c, itr) \
for (auto itr = c.begin(); itr != c.end(); itr++)

void printVector(vector<int>& v) {

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

void printVectorItr(vector<int>& v) {

    for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++) {
        cout << *itr << " ";
    }

    cout << endl;
}

int main() {

    int arr[] = {1,5,4,4,2};
    vector<int> v(arr, arr + sizeof(arr)/sizeof(arr[0]));
    printVector(v);

    vector<int> v2(v.begin(), v.begin() + v.size()/2);
    printVector(v2);

    reverse(v.begin(), v.end());
    printVector(v);

    printVectorItr(v);

    auto itr = find(v.begin(), v.end(), 10);
    if (itr == v.end()) {
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    printVector(v);

    int maxElement = *max_element(v.begin(), v.end());
    cout << "Max element is " << maxElement << endl;
    
    int minElement = *min_element(v.begin(), v.end());
    cout << "Min element is " << minElement << endl;

    int maxIdx = max_element(v.begin(), v.end()) - v.begin();
    cout << "Max idx is "<< maxIdx << endl;

    sort(all(v));
    cout << "Sorted vector is: " << endl;
    printVector(v);

    cout << "Traverse vector container using macros" << endl;
    int sum = 0;
    tr(v, itr) {
        sum += *itr;
    }
    cout << "Sum is " << sum << endl;

    return 0;
}


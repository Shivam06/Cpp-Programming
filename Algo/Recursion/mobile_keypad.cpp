#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

unordered_map<int, string> M;
vector<string> possibleWords(vector<int> nums) {
    
    if (nums.size() == 1) {
        vector<string> v;
        string chars = M[nums[0]];
        for (int i = 0; i < chars.size(); i++) {
            string tmp(1, chars[i]);
            v.push_back(tmp);
        }
        return v;
    }
    
    vector<int> tempV(nums.begin(), nums.end()-1);
    vector<string> prev = possibleWords(tempV);
    vector<string> v;
    string chars = M[nums[nums.size()-1]];
    for (int i = 0; i < chars.size(); i++) {
        string tmp(1, chars[i]);
        for (int j = 0; j < prev.size(); j++) {
            v.push_back(prev[j] + tmp);
        }
    }
    return v;
}

//Complete this function
void possibleWords(int a[],int N)
{
    M[2] = "abc";
    M[3] = "def";
    M[4] = "ghi";
    M[5] = "jkl";
    M[6] = "mno";
    M[7] = "pqrs";
    M[8] = "tuv";
    M[9] = "wxyz";
    vector<int> v(a, a+N);
    vector<string> output = possibleWords(v);
    sort(output.begin(), output.end());
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << " ";
    }
    //Your code here
}

int main() {
	int a[] = {2,5,7};
	possibleWords(a, 3);
}
#include<list>
#include<iostream>
#include<unordered_map>
using namespace std;

class LRUCache
{
private:
    int size;
    list<pair<int, int> > L;
    unordered_map<int, list<pair<int,int> >::iterator> M;
    
public:
    LRUCache(int cap)
    {
        size = cap;
        L.clear();
        M.clear();
    }
    
    int get(int key)
    {
        if (M.find(key) == M.end())
            return -1;

        auto itr = M.find(key);
        int val = (*(itr->second)).second;
        L.erase(itr->second);
        L.push_front(make_pair(key, val));
        M[key] = L.begin();
        return val;
    }
    
    void set(int key, int value)
    {
        if (M.find(key) == M.end() && M.size() == size) {
            M.erase(L.back().first);
            L.pop_back();
        } else if (M.find(key) != M.end()) {
            auto itr = M.find(key);
            L.erase(itr->second);
        }
        
        L.push_front(make_pair(key, value));
        M[key] = L.begin();
    }
    
};

int main() {
    LRUCache cache(2);
    cout << cache.get(1) << endl;
    cache.set(1,3);
    cout << cache.get(1) << endl;
    cache.set(2,5);
    cache.set(3,6);
    cout << cache.get(1) << endl;
}

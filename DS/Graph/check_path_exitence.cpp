#include<iostream>
#include<vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<vector<int> > vvi;
#define tr(c, it) for (auto it = c.begin(); it != c.end(); it++)
#define all(c) c.begin(), c.end()

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};

bool checkPathUtil(vector<vector<int> >& M, int N, int x, int y, vector<vector<int> >& visited) {
    
    if (x < 0 || y < 0 || x >= N || y >= N || visited[x][y] || M[x][y] == 0) {
        return false;
    }
    
    if (M[x][y] == 2)
        return true;
    
    visited[x][y] = 1;    
    
    for (int i = 0; i < 4; i++) {
        if (checkPathUtil(M, N, x + X[i], y + Y[i], visited)) {
            return true;
        }
    }
    
    return false;
}

bool checkPath(vector<vector<int> >& M, int N, int x, int y) {
    
    vector<vector<int> > visited(N, vector<int>(N, 0));
    
    return checkPathUtil(M, N, x, y, visited);
}

int main()
 {
	int T;
	cin>>T;
	
	for (int t = 0; t < T; t++) {
	    int N;
	    cin>>N;
	    int num, x, y;
	    vector<vector<int> > M(N, vector<int>(N, 0));
	   
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < N; j++) {
	            cin>>num;
	            if (num == 1) {
	                x = i;
	                y = j;
	            }
	            M[i][j] = num;
	        }
	    }
	    
	    cout << checkPath(M, N, x, y) << endl; 
	}
	return 0;
}
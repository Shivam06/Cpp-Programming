#include<iostream>
#include<vector>
using namespace std;

// Problem Link - https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1/

vector<int> dir{{-1, 0, 1}};

void dfs(int x, int y, vector<int> A[], int N, int M, vector<vector<bool> >& visited) {
    
    visited[x][y] = true;
    for (auto i: dir) {
        for (auto j: dir) {
            
            if (x + i < 0 || x + i >= N || y + j < 0 || y + j >=M) {
                continue;
            }
            
            if (A[x+i][y+j] == 0)
                continue;
            
            if (visited[x+i][y+j])
                continue;
                
            dfs(x+i, y+j, A, N, M, visited);
        }
    } 
}
    
/*  Function to find number of islands in the given graph
*   A[]: input array
*   N, M: Row and column of given matrix
*/
int findIslands(vector<int> A[], int N, int M) {

    int count = 0;
    vector<vector<bool> > visited(N, vector<bool>(M, false));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 0 || visited[i][j])
                continue;
                
            dfs(i, j, A, N, M, visited);
            count++;
        }
    }
    
    return count;
}

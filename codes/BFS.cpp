#include <iostream>
#include <queue>
#include <bits/stdc++.h>

using namespace std;

void BFS(int vtx, int A[][8], int n){
    queue<int> Q;
    int visited[8] = {0};  // Standard initialization
    
    // Initial
    cout << vtx << ", " << flush;  // Visit vertex
    visited[vtx] = 1;
    Q.push(vtx);  // Use push instead of emplace
    
    // Explore
    while (!Q.empty()){
        int u = Q.front();  // Vertex u for exploring
        Q.pop();
        for (int v=1; v<=n; v++){  // Adjacent vertices of vertex u
            if (A[u][v] == 1 && visited[v] == 0){  // Adjacent vertex and not visited
                cout << v << ", " << flush;  // Visit vertex
                visited[v] = 1;
                Q.push(v);  // Use push instead of emplace
            }
        }
    }
    cout << endl;
}

int main (){
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};

    cout << "Vertex: 1 -> " << flush;
    BFS(1, A, 8);
    cout << endl;

    cout << "Vertex: 4 -> " << flush;
    BFS(4, A, 8);
    cout << endl;


    return 0;
}
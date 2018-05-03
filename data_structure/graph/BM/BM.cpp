//Bipartite Matching
#include<bits/stdc++.h>
using namespace std;
#define N 1005

int A[N], B[N];

vector<int> G[N];
bool visit[N];

bool dfs(int a){
	visit[a] = 1;
	for (int i = 0; i < G[a].size(); ++i){
		int nxt = G[a][i];
		if (B[nxt] == -1 || !visit[B[nxt]] && dfs(B[nxt])){		//no match or pushing
			A[a] = nxt;
			B[nxt] = a;
			return 1;
		}
	}
	return 0;
}

int BM(){
    int c=0;
    memset(A, -1, sizeof(A));
    memset(B, -1, sizeof(B));
	for (int i = 0; i < n; ++i){
		if (A[i] == -1){
			memset(visit, 0, sizeof(visit));
			if (dfs(i)) c++;
		}
	}
    return c;
}

int main(){
	/*
    make graph (A - adj list)
    */
	cout << BM();
	return 0;
}

/*
Hopcroft-Karp algorithm
*/
#include<bits/stdc++.h>
using namespace std;
#define N 4000
int A[N+1], B[N+1];
vector<int> G[N+1];
int lev[N+1];

bool bfs(int n) {
	queue<int> q;
	for (int i = 0; i < n; ++i) {
		if (A[i] == N) {			//no matching (lev = 0)
			lev[i] = 0;
			q.push(i);
		}
		else lev[i] = INT_MAX;		//matching (lev = INF)
	}
	lev[N] = INT_MAX;

	while (!q.empty()) {			//leveling
		int cur = q.front();
		q.pop();

		if (lev[cur] < lev[N]) {	//smaller lev of no matching (if bigger not search)
			for (int i = 0; i < G[cur].size(); ++i){
				int nxt = G[cur][i];
				if (lev[B[nxt]] == INT_MAX) {	//if not visited
					lev[B[nxt]] = lev[cur] + 1;
					q.push(B[nxt]);
				}
			}
		}
	}
	return (lev[N] != INT_MAX);	//if no matching exist -> true
    }

int path[N+1];

bool dfs(int u) {
	if (u == N) return 1;	//find mathing
	for (int &i = path[u]; i < G[u].size(); ++i) {
		int nxt = G[u][i];
		if (lev[B[nxt]] == lev[u] + 1) {
			if (dfs(B[nxt])) {
				A[u] = nxt;
				B[nxt] = u;
				return 1;
			}
		}
	}
	return 0;
}

int HK(int n, int m) {
	//init
	for (int i = 0; i < n; ++i) {
		A[i] = N;	//no matching
	}
	for (int i = 0; i < m; ++i) {
		B[i] = N; //no mathcing
	}

	int mf = 0;
	while (bfs(n)) {              //idea: Dinic
		for (int i = 0; i < n; ++i) {
			if (A[i] == N) {
				memset(path, 0, sizeof(path));
				if(dfs(i))	mf++;
			}
		}
	}
	return mf;
}

int main() {
	int n, m;
	/*
    make graph
    */
	cout << HK(n, m);   //A num, B num
	return 0;
}
//ref:
//https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/

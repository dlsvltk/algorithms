/*
Ford-Fulkerson algorithm
input: source, destination, (graph - adjacent list, capacity, flow, path)
output: maximum flow
*/
#include<bits/stdc++.h>
using namespace std;

#define N 100

vector<int> G[N];
int C[N][N];
int F[N][N];
int path[N];
int S, D;    //source, destination

bool dfs(int s){
	if (s == 1) return 1;
	for (int i = 0; i < G[s].size(); ++i){
		int nxt = G[s][i];
		if (C[s][nxt] - F[s][nxt] > 0 && path[nxt] == -1){	//exist capacity & not visit
			path[nxt] = s;
			if (dfs(nxt)) return 1;	//sink
		}
	}
	return 0;
}

int FF(int s, int d){   //input: source, destination
	int MF=0;
	while (1){
		memset(path, -1, sizeof(path));

		if (dfs(s) == 0) break;	//no more path

		int flow = INT_MAX;
		for (int i = d; i != 0; i = path[i]){		//calculate min path
			flow = min(flow, C[path[i]][i] - F[path[i]][i]);
		}

		for (int i = d; i != 0; i = path[i]){		// add reverse;
			F[path[i]][i] += flow;
			F[i][path[i]] -= flow;
		}
		//+ min;
		MF += flow;
	}
	return MF;
}

int main(){
    /*
    make network
    */
    cout << FF(S, D);
    return 0;
}

/*
Dinic algorithm
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


int level[N];

bool D_bfs(int s, int d){
	memset(level, -1, sizeof(level));
	level[s] = 1;

	queue<int> q;
	q.push(s);	//source
	while (!q.empty()){
		int cur = q.front();
		q.pop();
		for (int i = 0; i < G[cur].size(); ++i){
			int nxt = G[cur][i];
			if (level[nxt] == -1 && C[cur][nxt] - F[cur][nxt] > 0){		//not visit & exist capacity
				level[nxt] = level[cur] + 1;
				q.push(nxt);
			}
		}
	}
	return level[d] != -1;
}

int v_edge[N];

int D_dfs(int cur, int d, int f){
	if (cur == d) return f;
	// each edge not repeat search by no cycle (level graph)
	for (int &i = v_edge[cur]; i < G[cur].size(); ++i){
		int nxt = G[cur][i];
		if (level[nxt] == level[cur] + 1 && C[cur][nxt] - F[cur][nxt] > 0){
			int mf = D_dfs(nxt, d, min(f,C[cur][nxt]-F[cur][nxt]));
			if (mf > 0){
				F[cur][nxt] += mf;
				F[nxt][cur] -= mf;
				return mf;
			}
		}
	}
	return 0;
}

int DN(int s, int d){
    int MF=0;
    while (D_bfs(s,d)){
        memset(v_edge, 0, sizeof(v_edge));
        while (1){
            int f = D_dfs(s, d, INT_MAX);
            if (f == 0) break;
            MF += f;
        }
    }
	return MF;
}

int main(){
    /*
    make network
    */
    cout<<DN(S,D);
    return 0;
}

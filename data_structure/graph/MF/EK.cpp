/*
Edmonds-Karp algorithm
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

int EK(int s, int d){
    int MF=0;
    while (1){
        memset(path, -1, sizeof(path));

        //bfs
        queue<int> q;
        q.push(s);	//source
        while (!q.empty()){
            int cur = q.front();
            q.pop();

            for (int i = 0; i < G[cur].size(); ++i){
                int nxt = G[cur][i];
                if (C[cur][nxt] - F[cur][nxt] > 0 && path[nxt] == -1){		//exist capacity & not visit
                    q.push(nxt);
                    path[nxt] = cur;
                    if (nxt == d) break;	//sink	(destination 25)
                }
            }
        }

        if (path[d] == -1) break;	//no more path

        int flow = INT_MAX;
        for (int i = d;i!=s;i=path[i]){		//calculate min path
            flow = min(flow, C[path[i]][i] - F[path[i]][i]);
        }

        for (int i=d;i!=s;i=path[i]){		// add reverse;
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
    cout<<EK(S,D);
    return 0;
}

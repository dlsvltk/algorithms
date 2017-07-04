#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
stack<int> s;
vector<int> adj[10001];
vector<vector<int>> SCC;
int ord[10001];
bool ends[10001];
int orders;
int scc_n[10001];
int sn;
int dfs(int v){
	orders++;
	ord[v] = orders;
	s.push(v);

	int res = ord[v];

	for (int i = 0; i < adj[v].size(); i++){
		int nxt = adj[v][i];
		if (ord[nxt] == 0){
			res = min(res, dfs(adj[v][i]));
		}
		else if (!ends[nxt]) res = min(res, ord[nxt]);
	}
	if (res == ord[v]){
		vector<int> scc;
		while (1){
			int t = s.top();
			s.pop();
			scc.push_back(t);
			ends[t] = 1;
			scc_n[t] = sn;
			if (t == v) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
		sn++;
	}

	ends[v] = 1;
	return res;
}


int main() {
	int v, e;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
	}
	for (int i = 1; i <= v; i++){
		if (ord[i] == 0) dfs(i);
	}
	sort(SCC.begin(), SCC.end());

	for (int i = 0; i < sn; i++){
		for (int k = 0; k < SCC[i].size(); k++){
			printf("%d ", SCC[i][k]);
		}
		printf("-1\n");
	}
	return 0;
}
//BOJ 2150
//ref> http://blog.naver.com/prologue/PrologueList.nhn?blogId=kks227 

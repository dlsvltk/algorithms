#pragma warning(disable: 4996)
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int p[100001][18];
int dep[100001];
vector<int> edge[100001];
int l;
void tree_dfs(int v){
	for (int i = 0; i < edge[v].size(); i++){
		int nxt = edge[v][i];
		if (dep[nxt] == 0){	//init value 0
			p[nxt][0] = v;
			dep[nxt] = dep[v] + 1;
			tree_dfs(nxt);
		}
	}
}


int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	memset(p, -1, sizeof(p));
	dep[1] = 1;
	tree_dfs(1);

	for (int j = 0; j < 17; j++){
		for (int i = 1; i <= n; i++){
			if (p[i][j] != -1){
				p[i][j + 1] = p[p[i][j]][j];
			}
		}
	}
	scanf("%d", &m);
	while (m--){
		int u, v;
		scanf("%d %d", &u, &v);
		if (dep[u] < dep[v]) swap(u, v);
		int diff = dep[u] - dep[v];
		for (int i = 0; diff; i++){
			if (diff & 1) u = p[u][i];
			diff >>= 1;
		}

		if (u != v){
			for (int i = 17; i >= 0; i--){
				if (p[u][i] != -1 && p[u][i] != p[v][i]){
					u = p[u][i];
					v = p[v][i];
				}
			}
			u = p[u][0];
		}
		printf("%d\n", u);
	}
	return 0;
}
//BOJ 11438
//ref> http://blog.naver.com/prologue/PrologueList.nhn?blogId=kks227

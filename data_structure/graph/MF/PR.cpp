//not complete
/*
Push-Relabel algorithm
input: source, destination, (graph - adjacent list, capacity, flow, path)
output: maximum flow
*/
#include<bits/stdc++.h>
using namespace std;
#define N 100
vector<int> G[N];

int path[N];
int C[N][N];
int F[N][N];
int h[N];
int exc[N];
int maxh[N];
int S,D;    //source, destination

int PR(int s, int d){
	//init
	h[s] = N - 1;	//source height
	for (int i = 0; i < N; ++i){	//source -> push (adj: excess flow)
		F[s][i] = C[s][i];	
		F[i][s] = -F[s][i];
		exc[i] = C[s][i];	
	}
	//push & relabel
	for (int sz = 0;;) {
		if (sz == 0) {
			for (int i = 0; i < N; ++i)
			if (i != s && i != d && exc[i] > 0) {
				if (sz != 0 && h[i] > h[maxh[0]])
					sz = 0;
				maxh[sz++] = i;
			}
		}
		if (sz == 0)
			break;
		while (sz != 0) {
			int i = maxh[sz - 1];
			bool pushed = false;
			for (int j = 0; j < N && exc[i] != 0; ++j) {
				if (h[i] == h[j] + 1 && C[i][j] - F[i][j] > 0) {
					int df = min(C[i][j] - F[i][j], exc[i]);
					F[i][j] += df;
					F[j][i] -= df;
					exc[i] -= df;
					exc[j] += df;
					if (exc[i] == 0)
						--sz;
					pushed = true;
				}
			}
			if (!pushed) {
				h[i] = INT_MAX;
				for (int j = 0; j < N; ++j)
				if (h[i] > h[j] + 1 && C[i][j] - F[i][j] > 0)
					h[i] = h[j] + 1;
				if (h[i] > h[maxh[0]]) {
					sz = 0;
					break;
				}
			}
		}
	}

	int flow = 0;
	for (int i = 0; i < N; i++)
		flow += F[s][i];

	return flow;
}

int main(){
	/*
    make network
    */
	cout << PR(S,D);
	return 0;
}

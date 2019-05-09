#include <bits/stdc++.h>
using namespace std;
//O(m);
//check if the connected component of u is a bipartite graph.
//color : 1 or 2.  0 for uncolored.
// initially : memset(color, 0, sizeof(color));
int color[maxn];
VI G[maxn];
bool bipartite(int u) {
	for (int i = 0; i < G[u].size(); i++) {
		int v = G[u][i];
		if (color[v] == color[u]) return false;
		if (!color[v]) {
			color[v] = 3 - color[u];
			if (!bipartite(v)) return false;
		}
	}
	return true;
}


int main() {
	return 0;
}
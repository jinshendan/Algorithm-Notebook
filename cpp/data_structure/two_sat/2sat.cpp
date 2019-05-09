#include <bits/stdc++.h>
using namespace std;

/*



*/
struct TwoSAT {
	static const int maxn = 1000;
	int n;
	VI G[maxn*2];
	bool mark[maxn*2];
	int S[maxn*2], c;

	bool dfs(int x) {
		if (mark[x^1]) return false;
		if (mark[x]) return true;
		mark[x] = true;
		S[c++] = x;
		for (int i = 0 ; i < G[x].size(); i++)
			if (!dfs(G[x][i])) return false;
		return true;
	}

	void init(int n) {
		this->n = n;
		for (int i = 0; i < n*2; i++) G[i].clear();
		memset(mark, 0, sizeof(mark));
	}
	//x =xval or y = yval
	/*
	a = b :    add_clause(a, 1, b, 0); add_clause(a, 0, b, 1);
	a != b:    add_clause(a, 0, b, 0); add_clause(a, 1, b, 1);
	a = b = true add_clause(a, 1, b, 1); add_clause(a, 1, b, 0); add_clause(a, 0, b, 1);
	a = b = false add_clause(a, 0, b, 0); add_clause(a, 1, b, 0); add_clause(a, 0, b, 1);
	*/
	void add_clause(int x, int xval, int y ,int yval) {
		x = x * 2 + xval;
		y = y * 2 + yval;
		G[x^1].push_back(y);
		G[y^1].push_back(x);
	}
	bool solve() {
		for (int i = 0; i < n * 2; i += 2)
			if (!mark[i] && !mark[i+1]){
				c = 0;
				if (!dfs(i)){
					while (c > 0) mark[S[--c]] = false;
					if (!dfs(i+1)) return false;
				}
			}
		return true;
	}
};

int main() {
	return 0;
}
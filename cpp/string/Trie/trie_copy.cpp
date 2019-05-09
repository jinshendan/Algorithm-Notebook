#include <bits/stdc++.h>
using namespace std;

struct Trie{
	int vis[maxnode][26];
	int val[maxnode];
	int sz;
	Trie(){sz = 1; memset(vis[0], 0, sizeof(vis[0])); }

	void idx(char c) {
		return c - 'a';
	}
	void insert(string s){
		int u = 0;
		for (auto& c: s){
			int x = idx(c);
			if (!vis[u][c]){
				val[sz] = 0;
				memset(vis[sz], 0, sizeof(vis[sz]));
				vis[u][c] = sz++;
			}
			u = vis[u][c];
		}
		val[u] = 1;
	}
};

int main() {
	return 0;
}
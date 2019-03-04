#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	static const int maxnode = 100000;
	struct Trie{
		int ch[maxnode][26];
		int val[maxnode];
		int sz;
		int best;
		string bs;
		Trie(){sz = 1; best = 0; memset(ch[0], 0, sizeof(ch[0])); }
		int idx(char c) {return c - 'a';}

		void insert(string s){
			int u = 0, n = s.length();
			for (int i = 0; i < n; i++){
				int c = idx(s[i]);
				if (!ch[u][c]){
					memset(ch[sz], 0, sizeof(ch[sz]));
					val[sz] = 0;
					ch[u][c] = sz++;
				}
				u = ch[u][c];
			}
			val[u] = 1;
		}


		void dfs(int u, int dep, string s){
			if (dep > best){
				best = dep;
				bs = s;
			}
			for (int i = 0; i < 26; i++){
				if (ch[u][i] and val[ch[u][i]])
					dfs(ch[u][i], dep+1, s + char(i + 'a'));
			}
		}
	};

	string longestWord(vector<string>& words) {
		Trie* T = new Trie();
		for (auto& s: words) T->insert(s);
		T->dfs(0, 0, "");
		return T->bs;        
	}
};

int main() {
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

void pre_kmp(string s, vector<int>& pnext){
	int m = s.length();
	pnext.resize(m+1);
	int i, j;
	i = 0; j = pnext[0] = -1;
	while (i < m) {
		while (j != -1 and s[i] != s[j]) j = pnext[j];
		pnext[++i] = ++j;
	}
}

int kmp(string s, string t){
	int m = s.length();
	int n = t.length();
	vector<int> pnext;
	pre_kmp(s, pnext);
	int i, j;
	i = j = 0;
	while (i < m){
		while (j!= -1 and t[i] != s[j]) j = pnext[j];
		i++; j++;
		if (j >= m) return i - m;
	}
	return -1;
}
int main(){

	return 0;
}
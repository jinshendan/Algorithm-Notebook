#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
	vector<int> father, size;

	UnionFind(int n):father(n), size(n){
		for (int i = 0; i < n; i++){
			father[i] = i;
			size[i] = 1;
		}
	}

	int find(int x){
		return father[x] = (x == father[x])?x:find(father[x]);
	}

	void merge(int x, int y){
		int fx = find(x);
		int fy = find(y);
		if (fx != fy){
			father[fx] = fy;
			size[fy] += size[fx];
		}
	}
};

int main(){
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int SIZE = 5000;
int deg[SIZE];
int ord[SIZE]; // ord start with 1
void TopSort(vector<int> G[], int n) {
    memset(deg, 0, sizeof(deg));
    memset(ord, 0, sizeof(ord));
    fin(i, n) for(int j : G[i]) deg[j]++;
    queue<int> Q;
    fin(i, n) if(!deg[i]) {
            Q.push(i);
            ord[i] = 1;
        }
    while(!Q.empty()) {
        int i = Q.front(); Q.pop();
        for(int j : G[i]) {
            deg[j]--;
            if(!deg[j]) {
                Q.push(j);
                ord[j] = ord[i] + 1;
            }
        }
    }
}

int main(){
	return 0;
}
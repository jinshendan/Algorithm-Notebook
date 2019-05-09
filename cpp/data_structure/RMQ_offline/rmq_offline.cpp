#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000;
//This is a offline version of RMQ.
//O(nlogn)

/* 2^20 > 10^6 */
/* Start from index 0 */

int d[maxn][20];
int n;

void RMQ_init(const VI& A){
	int n = A.size();
	for (int i = 0; i < n; i++) d[i][0] = A[i];
	for (int j = 1; (1<<j) <= n; j++)
		for (int i = 0; i + (1<<j) -1 < n; i++)
			d[i][j] = min(d[i][j-1], d[i+ (1<<(j-1))][j-1]);
}

int RMQ_query(int L, int R) {
	int k = 0;
	while ( (1<<(k+1)) <= R-L+1) k++;
	return min(d[L][k], d[R-(1<<k)+1][k]);
}

int main() {
	return 0;
}
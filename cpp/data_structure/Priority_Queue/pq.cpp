#include <bits/stdc++.h>
using namespace std;

// in increasing order of timestamp
struct Node {
	int Value, Period, Time;
	bool operator < (const Node& a) const {
		return Time > a.Time || (Time == a.Time && Value > a.Value);
	}
};


int main() {
	char s[20];
	priority_queue<Node> pq;

	while (scanf("%s", s) && s[0] != '#') {
		Node tmp;
		scanf("%d%d", &tmp.Value, &tmp.Period);
		tmp.Time = tmp.Period;
		pq.push(tmp);
	}

	int k;
	scanf("%d", &k);
	while (k--) {
		Node r = pq.top();
		pq.pop();
		printf("%d\n", r.Value);
		r.Time += r.Period;
		pq.push(r);
	}
	return 0;
}
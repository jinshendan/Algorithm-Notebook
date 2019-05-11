#include <bits/stdc++.h>
using namespace std;
/*
Implementation of Dijkstra's algorithm using adjacency lists
and priority queue for efficiency.
Running time: O(|E| log |V|)
USAGE: edges: pair of weight/destination, source, target
*/
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;

void Dijkstra(VVPII edges, int s, int t) {
    // use priority queue in which top element has the "smallest" priority
    priority_queue<PII, VPII, greater<PII> > Q;
    VI dist(edges.size(), INF), dad(edges.size(), -1);
    Q.push(make_pair (0, s));
    dist[s] = 0;
    while(!Q.empty()){
        PII p = Q.top();
        if (p.second == t) break;
        Q.pop();
        int here = p.second;
        for(VPII::iterator it=edges[here].begin(); it!=edges[here].end(); it++){
            if(dist[here] + it->first < dist[it->second]){
                dist[it->second] = dist[here] + it->first;
                dad[it->second] = here;
                Q.push (make_pair (dist[it->second], it->second));
            }
        }
    }
    // dist contains distances
}
int main() {
    return 0;
}
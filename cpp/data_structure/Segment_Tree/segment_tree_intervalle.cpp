#include <bits/stdc++.h>
using namespace std;

/*
    UVa11992 Fast Matrix Operations
    leaves always keep the set label (pushdown only for internal nodes)
*/


const int maxnode = 1<<17;
const int INF = 1000000000;

int op, x1, x2, y1, y2, x, v;

struct IntervalTree {
    int sumv[maxnode], minv[maxnode], maxv[maxnode], setv[maxnode], addv[maxnode];

    // maintain information
    void maintain(int o, int L, int R) {
        int lc = o*2, rc = o*2+1;
        if(R > L) {
            sumv[o] = sumv[lc] + sumv[rc];
            minv[o] = min(minv[lc], minv[rc]);
            maxv[o] = max(maxv[lc], maxv[rc]);
        }
        if(setv[o] >= 0) { minv[o] = maxv[o] = setv[o]; sumv[o] = setv[o] * (R-L+1); }
        if(addv[o]) { minv[o] += addv[o]; maxv[o] += addv[o]; sumv[o] += addv[o] * (R-L+1); }
    }

    // pushdown label
    void pushdown(int o) {
        int lc = o*2, rc = o*2+1;
        if(setv[o] >= 0) {
            setv[lc] = setv[rc] = setv[o];
            addv[lc] = addv[rc] = 0;
            setv[o] = -1; // Clear label
        }

        if(addv[o]) {
            addv[lc] += addv[o];
            addv[rc] += addv[o];
            addv[o] = 0; // Clear label
        }
    }

    void update(int o, int L, int R) {
        int lc = o*2, rc = o*2+1;
        if(y1 <= L && y2 >= R) { // modify label     
            if(op == 1) addv[o] += v;
            else { setv[o] = v; addv[o] = 0; }
        } else {
            pushdown(o);
            int M = L + (R-L)/2;
            if(y1 <= M) update(lc, L, M); else maintain(lc, L, M);
            if(y2 > M) update(rc, M+1, R); else maintain(rc, M+1, R);
        }
        maintain(o, L, R);
    }

    void query(int o, int L, int R, int& ssum, int& smin, int &smax) {
        int lc = o*2, rc = o*2+1;
        maintain(o, L, R); 
        if(y1 <= L && y2 >= R) {
            ssum = sumv[o];
            smin = minv[o];
            smax = maxv[o];
        } else {
            pushdown(o);
            int M = L + (R-L)/2;
            int lsum = 0, lmin = INF, lmax = -INF;
            int rsum = 0, rmin = INF, rmax = -INF;
            if(y1 <= M) query(lc, L, M, lsum, lmin, lmax); else maintain(lc, L, M);
            if(y2 > M) query(rc, M+1, R, rsum, rmin, rmax); else maintain(rc, M+1, R);
            ssum = lsum + rsum;
            smin = min(lmin, rmin);
            smax = max(lmax, rmax);
        }
    }
};

const int maxr = 20 + 5;

IntervalTree tree[maxr];

int main() {
    int r, c, m;
    while(scanf("%d%d%d", &r, &c, &m) == 3) {
        memset(tree, 0, sizeof(tree));
        for(x = 1; x <= r; x++) {
            memset(tree[x].setv, -1, sizeof(tree[x].setv));
            tree[x].setv[1] = 0;
        }
        while(m--) {
            scanf("%d%d%d%d%d", &op, &x1, &y1, &x2, &y2);
            if(op < 3) {
                scanf("%d", &v);
                for(x = x1; x <= x2; x++) tree[x].update(1, 1, c);
            } else {
                int gsum = 0, gmin = INF, gmax = -INF;
                for(x = x1; x <= x2; x++) {
                    int ssum, smin, smax;
                    tree[x].query(1, 1, c, ssum, smin, smax);
                    gsum += ssum; gmin = min(gmin, smin); gmax = max(gmax, smax);
                }
                printf("%d %d %d\n", gsum, gmin, gmax);
            }
        }
    }
    return 0;
}

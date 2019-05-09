#include <bits/stdc++.h>
using namespace std;
/*
pnext[i+1] denotes the length of the longest substring ending at s[i] which is also a prefix of s
at mean time
*/
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

// s: pattern ; t: text
int kmp(string s, string t) {
    int i, j; 
    int num_occurence = 0;
    vector<int> pnext;
    int m = s.length();
    int n = t.length();
    pre_kmp(s, pnext);
    i = j = 0;
    while (i < n){
        while (j != -1 and t[i] != s[j]) j = pnext[j];
        i++; j++;
        if (j >= m){
            num_occurence ++;
            j = pnext[j];
            // return i - m; 
        }
    }
    return num_occurence;
    // return -1; 
}

int main(){
    cout << kmp("abc", "ggabcabcd") << endl;
}
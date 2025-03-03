#include <bits/stdc++.h>
using namespace std;


static const int MAXN = 2e5; 
static const int LOG = 21;    

int n, q;
vector<int> adj[MAXN];       
int anc[MAXN][LOG];          


void buildAncestorTable(int node, int parent) {
    anc[node][0] = parent;

    for (int i = 1; i < LOG; i++) {
        int prev = anc[node][i - 1];
        if (prev == -1) {
            anc[node][i] = -1;
        } else {
            anc[node][i] = anc[prev][i - 1];
        }
    }

    
    for (int child : adj[node]) {
        if (child == parent) continue;
        buildAncestorTable(child, node);
    }
}


int query(int node, int k) {

    if (node == -1) return -1;

    for (int i = 0; i < LOG; i++) {
        if (k & (1 << i)) {
            node = anc[node][i];
            if (node == -1) break;
        }
    }
    return node;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a; -- b;          
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    
    buildAncestorTable(0, -1);

    // while (q--) {
    //     int x, k;
    //     cin >> x >> k;
    //     x--;            
    //     int ans = query(x, k);
    //     cout << (ans == -1 ? -1 : ans + 1) << "\n";
    // }

    return 0;
}

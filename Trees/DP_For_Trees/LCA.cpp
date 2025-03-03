#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const ll mxN = 2 * 1e5;
const ll LOG = 20;

ll n,  q;
vector<ll> tree[mxN + 1];
vector<ll> depth(mxN + 1);
ll anc[mxN][LOG];          


void buildAncestorTable(ll node, ll parent) {
    anc[node][0] = parent;

    for (ll i = 1; i < LOG; i++) {
        ll prev = anc[node][i - 1];
        if (prev == -1) {
            anc[node][i] = -1;
        } else {
            anc[node][i] = anc[prev][i - 1];
        }
    }
    
    for (ll child : tree[node]) {
        if (child == parent) continue;
        buildAncestorTable(child, node);
    }
}



void dfs(ll node, ll par, ll d){
    depth[node] = d;

    for(ll child : tree[node]){
        if(child == par) continue;
        dfs(child, node, d + 1);
    }
}

void get_lca(ll u, ll v){
    if(depth[u] < depth[v]){
        swap(u, v);
    }

    ll k = depth[u] - depth[v];

    for(ll j = LOG - 1; j >= 0; --j){
        if(k & (1 << j)){
            u = anc[u][j];
        }
    }

    if(u == v){
        cout << u + 1 << endl;
        return;
    }

    for(ll j = LOG - 1; j >= 0; --j){
        if(anc[u][j] != anc[v][j]){
            u = anc[u][j];
            v = anc[v][j];
        }
    }

    cout << anc[u][0] + 1 << endl;
}

void solve(){
    cin >> n >> q;

    for(ll i = 2; i <= n; i++){
        ll boss;
        cin >> boss;
        --boss;
        tree[boss].push_back(i - 1);
    }

    dfs(0, -1, 0);
    buildAncestorTable(0, -1);

    for(ll i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
        --a; --b;
        get_lca(a, b);
    }
}

void speed(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



int main(){
    speed();
    solve();
    return 0;
}
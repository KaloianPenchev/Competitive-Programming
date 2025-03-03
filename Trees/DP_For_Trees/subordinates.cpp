#include <bits/stdc++.h>

#define endl "\n"
#define ll long long

const ll MAXN = 1e5;

using namespace std;

vector<vector<ll>> adj(2 * MAXN + 1); 
ll dp[2 * MAXN + 1]; 

void dfs(ll node, ll par) {
    ll subs = 0;

    for (ll cur : adj[node]) {
        if (cur != par) {
            dfs(cur, node);
            subs += 1 + dp[cur]; 
        }
    }
    dp[node] = subs; 
}

void fastIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fastIO();
    ll n;
    cin >> n;

    for (ll i = 2; i <= n; i++) {
        ll x;
        cin >> x;
        adj[x].push_back(i);
        
    }

    
    dfs(1, -1);

    
    for (ll i = 1; i <= n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}

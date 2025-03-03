#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const ll mxN = 2 * 1e5;

ll n;
vector<ll> tree[mxN + 1];
ll dist[2][mxN + 1];

int dfs(ll node, ll par, ll i, ll d){
    dist[i][node] = d;
    
    ll opt = -1;

    for(ll child : tree[node]){
        if(child != par){
            ll x = dfs(child, node, i, d + 1);
            
            if(opt == -1 || ( dist[i][x] > dist[i][opt] )){
                opt = x;
            }
        }
    }
    
    return opt == -1 ? node : opt;
}

void input(){
    cin >> n;

    for(int i = 0; i < n - 1; i++){
        ll x, y;
        cin >> x >> y;
        --x; --y;

        tree[x].push_back(y);
        tree[y].push_back(x);
    }
}

void speed(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}



int main(){
    speed();
    input();
    ll f_node = dfs(0, -1, 0, 0);
    ll s_node = dfs(f_node, -1, 0, 0);

    dfs(s_node, -1, 1, 0);

    for(ll i = 0; i < n; i++){
        cout << max(dist[0][i], dist[1][i]) << " ";
    }
}
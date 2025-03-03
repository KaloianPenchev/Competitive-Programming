#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const ll mxN = 2 * 1e5;

ll n, f_node, dist;
vector<ll> tree[mxN + 1];

void dfs(ll node, ll par, ll d){
    for(ll child : tree[node]){
        if(child != par){
            dfs(child, node, d + 1);
        }
    }
    if(d > dist){
        dist = d;
        f_node = node;
    }
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
    dfs(0, -1, 0);
    
    dist = 0;
    dfs(f_node, -1, 0);

    cout << dist << endl;
}
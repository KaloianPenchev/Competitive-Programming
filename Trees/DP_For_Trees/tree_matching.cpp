#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl '\n'

const ll mxN = 2 * 1e5;

ll n;
vector<vector<ll>> tree(mxN + 1);
ll dp[mxN + 1][2];

void dfs(ll node, ll par){
    for(ll child : tree[node]){
        if(child != par){
            dfs(child, node);
            dp[node][0] += max(dp[child][0], dp[child][1]);
        }    
    }

    for(ll child : tree[node]){
        if(child != par){
            dp[node][1] = max(dp[node][1],  1 + dp[child][0] + dp[node][0] - max(dp[child][0], dp[child][1]));
        }
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
    dfs(0, -1);
    cout << max(dp[0][0], dp[0][1]) << endl;
}
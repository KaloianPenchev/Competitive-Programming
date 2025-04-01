#include<bits/stdc++.h>

using namespace std;

const int MAXN = 2 * 1e5 + 5;
const int MAXM = 3 * 1e5 + 5;

struct DSU {
    int par[MAXN], sz[MAXN];

    void init() {
        for(int i = 0; i < MAXN; i++){
            par[i] = i;
            sz[i] = 1;
        }
    }

    int find(int x) {
        return par[x] == x ? x : par[x] = find(par[x]);
    }

    void union_sets(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) {
            if(sz[a] < sz[b]) swap(a, b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }

    bool connected(int a, int b) {
        return find(a) == find(b);
    }
};

struct Edge{
    int from;
    int to;
    int risk;
    int cost;
};

struct to_node{
    int to;
    int risk;
    int cost;
};

int n, m;
vector<Edge> g1(MAXM);
vector<vector<to_node>> mst(MAXM);


void add_edge(int& a, int &b, int& c, int& d){
    mst[a].push_back({b, c, d});
    mst[b].push_back({a, c, d});
}

bool cmp(const Edge& e1, const Edge& e2){
    return e1.risk < e2.risk;
}


void build_mst(){
    DSU d; d.init();

    sort(g1.begin(), g1.end(), cmp);

    int counter = g1.size();

    for(auto& edge : g1){
        if(counter == 0) break;
        int from = edge.from;
        int to = edge.to;
        int risk = edge.risk;
        int cost = edge.cost;

        if(!d.connected(from, to)){
            d.union_sets(from, to);
            add_edge(from, to, risk, cost);
            counter--;
        }
    }
}


void solve(){
    cin >> n >> m;
    
    for(int i = 0; i < m ; i++){
        int a, b, c, d; cin >> a >> b >> c >> d; --a, --b;
        g1.push_back({a, b, c, d});
    }
}

void speed(){
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    speed();
    solve();
    return 0;
}
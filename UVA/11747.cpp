#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct edge{
    int u;
    int v;
    int w;

    bool operator<(const edge& r) { return w < r.w; }
};


int n, m; 
vector<edge> edges;
int f[1001]; 
int ranks[1001];

void init(){
    edges.clear();
    for (int i = 0; i < n; ++i) f[i] = i, ranks[i] = 1;
}

int find(int x) { 
    return x == f[x] ? x : f[x] = find(f[x]); 
}

bool Union(int x, int y){

    x = find(x), 
    y = find(y);

    
    if (x == y) return false;

    
    if (ranks[x] > ranks[y]) f[y] = x;
    else if (ranks[x] < ranks[y]) f[x] = y;
    else f[y] = x, ranks[x]++;

    return true;
}

void kruskcal(){

    bool is_cycle = false; 

    for (auto& [u, v, w] : edges){

        if (Union(u, v)) continue;

        if (is_cycle) 
            cout << " ";
        cout << w;
        is_cycle = true;
    }

    if (!is_cycle) cout << "forest";
    cout <<endl;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (cin >> n >> m && !(!n && !m)){

        init();

        while (m--){
            int u, v, w;
            cin >> u >> v >> w;
            edges.push_back({ u, v, w });
        }

        sort(edges.begin(), edges.end());

        kruskcal();
    }
}
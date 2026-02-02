#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, sz;

int find(int a){
    if(parent[a] != a)
        parent[a] = find(parent[a]); // path compression
    return parent[a];
}

void unite(int a, int b){
    int pa = find(a);
    int pb = find(b);

    if(pa == pb) return;

    // union by size
    if(sz[pa] < sz[pb]){
        parent[pa] = pb;
        sz[pb] += sz[pa];
    } else {
        parent[pb] = pa;
        sz[pa] += sz[pb];
    }
}

int groupsize(int a){
    return sz[find(a)];
}

void Solve(){
    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    sz.assign(n + 1, 1);

    for(int i = 1; i <= n; i++)
        parent[i] = i;

    vector<vector<int>> grp(m);

    for(int i = 0; i < m; i++){
        int s;
        cin >> s;
        grp[i].resize(s);
        for(int j = 0; j < s; j++)
            cin >> grp[i][j];
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j + 1 < (int)grp[i].size(); j++){
            unite(grp[i][j], grp[i][j + 1]);
        }
    }

    for(int i = 1; i <= n; i++){
        cout << groupsize(i) << " ";
    }
    cout << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solve();
    return 0;
}



/*
Notes:
So this the standard union find question we will each adj friends like ai and ai+1 then check wether they belong so same ultimate parent and if yes then do nothing because they are already in same segment but if not they connect them and increase the each value of them
*/

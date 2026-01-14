/*
BRUTE FORCE APPROACH

#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

void Solve() {
    // write solution here
    int n;
    cin >> n;
    vector<pair<int,int>> arr(n-1);
    deque<pair<int,int>> dq;
    for(int i=0;i<n-1;i++){
        cin >> arr[i].first >> arr[i].second;
        dq.push_front({arr[i].first , arr[i].second});
    }
    vector<int> mark(n+1 , 0);
    mark[1] = 1;
    int cnt = 0;
    int c = 0;
    while(!dq.empty()){
        int s = dq.size();
        if(dq.empty()) break;
        for(int i=0;i<s;i++){
            c++;
            auto it = dq.back();
            int a = it.first;
            int b = it.second;
            dq.pop_back();
            if(1==mark[a] || 1==mark[b]){
               cout << a << " " << b << " " << endl;
                mark[a] = 1;
                mark[b] = 1;
            }
            else{
                dq.push_front({a , b});
            }
        }
        cnt++;
        cout << "\n";
    }
    cout << cnt << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}



*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <random>
#include <chrono>
#include <unordered_map>
#include <map>
#include <stack>
using namespace std;

#define int long long
#define INF (int)1e18

mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

map<pair<int,int> , int> mpp;
vector<int> dp;
vector<vector<int>> arr;
void dfs(int par , int var){
    for(auto it:arr[var]){
        if(it==par) continue;
        if(mpp[{par , var}] < mpp[{var , it}]){
            //cout << var << " " << it << ' ' << dp[var] << '\n';
            dp[it] = dp[var];
        }
        else dp[it] = dp[var] + 1 ;  //cout << var << " " << it << ' ' << dp[var]+1 << '\n';
        dfs(var , it);
    }

}
void Solve() {
    // write solution here
    int n;
    cin>>n;
    mpp.clear();
    dp.assign(n+1 , 0);
    arr.assign(n+1 , vector<int>());
    for(int i=0;i<n-1;i++){
        int a , b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
        mpp[{a , b}] = i+1;
        mpp[{b , a}] = i+1;
    }
    mpp[{0 , 1}] = 0;
    dp[1] = 1;
    dfs(0 , 1);

    cout << *max_element(dp.begin(), dp.end()) << '\n';

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        Solve();
    }

    return 0;
}


/*
Notes:
so in this program the main concept is that we have to use dfs and dp table
look we go for each child child and ask its parent that i which interation it get seleted
so the child will definitely get selected in either in that iteration on in the next iteration
if the the edge of node and its child occer after the node and its parent then the child will get selected in that iteration only other eise in the next iteration

*/



/*
Notes:

*/


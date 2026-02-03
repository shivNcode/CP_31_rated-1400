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

int query(int a , int b){
    cout << '?' << " " << a << " " << b << endl;
    cout.flush();
    int val;
    cin >> val;
    return val;
}

int common(pair<int,int> a , pair<int,int> b){
    if(a.first==b.first || a.first==b.second){
        return a.first;
    }
    return a.second;
}
int other(int a , pair<int,int> b){
    if(a==b.first){
        return b.second;
    }
    return b.first;
}
void Solve() {
    // write solution here.
    vector<int> arr = {4 , 8 , 15 , 16 , 23 , 42};
    int n = arr.size();
    map<int,pair<int,int>> mpp;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            mpp[arr[i]*arr[j]] = {arr[i] , arr[j]};
        }
    }
    vector<int> ans(6);
    auto p1 = mpp[query(1,2)];
    auto p2 = mpp[query(2,3)];
    ans[1] = common(p1 , p2);
    ans[0] = other(ans[1] , p1);
    ans[2] = other(ans[1] , p2);
    p1 = mpp[query(4,5)];
    p2 = mpp[query(5,6)];
    ans[4] = common(p1 , p2);
    ans[3] = other(ans[4] , p1);
    ans[5] = other(ans[4] , p2);
    cout << '!' <<" ";
    for(int it:ans){
        cout << it <<" ";
    }
    cout << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        Solve();
    }


    return 0;
}



/*
Notes:

*/

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

bool check(int k , vector<pair<int,int>>& arr){
    pair<int,int> curr = {0 , 0};
    for(int i = 0 ; i < arr.size() ; i++){
        cout<< i << " " << curr.first << " " << curr.second << " " << arr[i].first << " " << arr[i].second << endl;
        if(curr.second+k < arr[i].first || arr[i].second < curr.first-k){
            return false;
        }

        curr.first = max(curr.first+k , arr[i].first);
        curr.second = min(curr.second-k , arr[i].second);
    }

    return true;
}

void Solve(){
    int n;
    cin >> n;

    vector<pair<int,int>> arr(n);
    for(int i = 0 ; i < n ; i++){
        cin >> arr[i].first >> arr[i].second;
    }

    int l = 0 , r = 1e9;
    int ans = 0;
    if(check(0 , arr)) cout << "hua hai ";
    while(l <= r){
        int mid = l + (r - l) / 2;
        //cout << mid << " " << ans << " " << check(mid , arr) << endl;
        if(check(mid , arr)){
            ans = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }

    cout << ans << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--){
        Solve();
    }

    return 0;
}


/*
Notes:

*/

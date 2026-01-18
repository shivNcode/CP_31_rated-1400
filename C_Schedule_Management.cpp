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
bool check(int t , vector<int>& temp , int m){
    for(int i = 0 ; i<temp.size() ; i++){
        int val = temp[i];
        if(m<=0) return true;
        val = min(val , t);
        m-=val;
        if(val<t){
            int v = (t-val)/2;
            m-=v;
        }

    }
    if(m<=0) return true;
    return false;
}
void Solve() {
    // write solution here
    int n , m;
    cin >> n >> m;
    vector<int> arr(m);
    vector<int> temp(n , 0);
    int t = 0;
    for(int i=0;i<m;i++){
        cin >> arr[i];
        temp[arr[i]-1]++;
        t = max(temp[arr[i]-1] , t);
    }
    int l = 0 , r = t;
    sort(temp.begin() , temp.end());
    //for(auto it:temp) cout << it << " ";
    //cout << endl;
    //cout << t << endl;
    int ans = 0;
    while(l<=r){
        int mid = l + (r - l)/2;
       // cout << mid << endl;
        if(check(mid , temp , m)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout << ans << endl;

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

*/


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
    int n , m;
    cin >> n >> m;
    map<int,vector<int>> x;
    map<int,vector<int>> y;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int c;
            cin >> c;
            x[c].push_back(i);
            y[c].push_back(j);
        }
    }
    int total = 0;
    for (const auto &it : x) {
        vector<int> arr = it.second;
        int s = arr.size();
        sort(arr.begin() , arr.end());
        int sum = 0;

        for(int i=1;i<s;i++){
            //cout << arr[i] << " ";
            sum+=(arr[i]-arr[0]);
        }
        //cout << endl;
        //cout << sum << endl;
        int prev = sum;
        total+=prev;

        for(int i=1;i<s;i++){
            int added = prev - ((s - i)*abs(arr[i]-arr[i-1]));
            prev = added;
            //cout << added << endl;
            total+=added;
        }
    }
    for (const auto &it : y) {
         vector<int> arr = it.second;
        int s = arr.size();
        sort(arr.begin() , arr.end());
        int sum = 0;
        for(int i=1;i<s;i++){
            //cout << arr[i] << " ";
            sum+=(arr[i]-arr[0]);
        }
        //cout << endl;
        //cout << sum << endl;
        int prev = sum;
        total+=prev;
         for(int i=1;i<s;i++){
            int added = prev - ((s - i)*abs(arr[i]-arr[i-1]));
            prev = added;
            //cout << added << endl;
            total+=added;
        }
    }
    cout << total << endl;
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


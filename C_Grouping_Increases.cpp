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

// void Solve() {
//     // write solution here
//     int n;
//     cin>>n;
//     vector<int> arr(n) , temp;
//         cin>>arr[i];
//     }
//     int prev = arr[n-1];
//     for(int i=n-2;i>=0;i--){
//         if(arr[i]>=prev){
//             prev = arr[i];
//         }
//         else{
//             temp.push_back(arr[i]);
//         }
//     }

//     if(temp.size()>0) reverse(temp.begin() , temp.end());
//     int ans = 0;
//     int tt = temp.size();
//     for(int i=0;i<tt-1;i++){
//         if(i<tt-1 && temp[i]<temp[i+1]){
//             ans++;
//         }
//     }
//     cout<<ans<<endl;

// }

void Solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    stack<int> st;
    pair<int,int> check({0,0});
    int ans = 0;
    for(int i=0;i<n;i++){
        while(!st.empty() && st.top()<arr[i]){
            st.pop();
        }
        st.push(arr[i]);
        if(st.size()>check.first){
            check.first = st.size();
            check.second = i;
        }
    }
    vector<int> temp;
    for(int i=0;i<=check.second;i++){
        if(arr[i]<arr[check.second]){
            temp.push_back(arr[i]);
        }
    }
    for(int i = check.second+1;i<n;i++){
        temp.push_back(arr[i]);
    }
    cout<<check.first<<" "<<arr[check.second]<<endl;
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
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


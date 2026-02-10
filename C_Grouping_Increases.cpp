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

void Solve()
{
    // write solution here.
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    vector<int> p1 , p2;
    p1.push_back(1e9);
    p2.push_back(1e9);
    int ans = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=p1.back() && arr[i]<=p2.back()){
            if(p1.back()>p2.back()){
                p2.push_back(arr[i]);
            }
            else{
                p1.push_back(arr[i]);
            }
        }
        else if(arr[i]<=p1.back()){
            p1.push_back(arr[i]);
        }
        else if(arr[i]<=p2.back()){
            p2.push_back(arr[i]);
        }
        else{
            ans++;
            if(p1.back()>p2.back()){
                p2.push_back(arr[i]);
            }
            else{
                p1.push_back(arr[i]);
            }
        }
    }
    cout << ans << endl;

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        Solve();
    }

    return 0;
}

/*
Notes:

*/

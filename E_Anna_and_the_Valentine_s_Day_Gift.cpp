// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <deque>
// #include <random>
// #include <chrono>
// #include <unordered_map>
// #include <map>
// #include <stack>
// using namespace std;

// #define int long long
// #define INF (int)1e18

// mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());


// int firstDigit(int x) {
//     x = abs(x);
//     while (x >= 10)
//         x /= 10;
//     return x;
// }

// bool cmp(int a, int b) {
//     return firstDigit(a) < firstDigit(b);
// }

// bool cmp2(int a , int b){
//     int n = 0 , m = 0;
//     while(a%10==0){
//         a/=10;
//         n++;
//     }
//     while(b%10==0){
//         b/=10;
//         m++;
//     }
//     return n<m;
// }

// void Solve() {
//     // write solution here
//     int n , m;
//     cin>>n>>m;
//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     sort(arr.rbegin() , arr.rend() , cmp2);
//     bool alt = true;
//     for(int i=0;i<arr.size() ; i++){
//         if(arr[i]%10==0 && alt==true){
//             while(arr[i]%10==0){
//                 arr[i]/=10;
//             }
//             alt = false;
//         }
//         if(arr[i]%10==0 && alt==false){
//             alt = true;
//         }
//     }
//     sort(arr.begin() , arr.end() , cmp);
//     int sum = arr[0];
//     for(int i=1;i<arr.size();i++){
//         //cout<<arr[i]<<" ";
//         int dig = 1;
//         int val = arr[i];
//         while(val){
//             val/=10;
//             dig*=10;
//         }
//         //dig/=10;
//        // cout<<(dig)<<" "<<arr[i]<<" \n";
//     sum = (sum*dig) + arr[i];
//     }
//     //cout<<'\n'<<sum;
//     int comp = 1;
//     while(m--){
//         comp*=10;
//     }
//     //acout<<sum<<endl;
//     if(sum>comp) cout<<"Sasha"<<endl;
//     else cout<<"Anna"<<endl;
// }

// int32_t main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int t = 1;
//     cin >> t;
//     while (t--) {
//         Solve();
//     }

//     return 0;
// }


// /*
// Notes:

// */


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


bool cmp2(int a, int b) {
    int ca = 0, cb = 0;
    while (a % 10 == 0) {
        a /= 10;
        ca++;
    }
    while (b % 10 == 0) {
        b /= 10;
        cb++;
    }
    return ca > cb;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }


        sort(a.begin(), a.end(), cmp2);


        bool take = true;
        for (int i = 0; i < n; i++) {
            if (a[i] % 10 == 0) {
                if (take) {
                    while (a[i] % 10 == 0) {
                        a[i] /= 10;
                    }
                    take = false;
                } else {
                    take = true;
                }
            }
        }


        long long totalDigits = 0;
        for (int x : a) {
            if (x == 0) {
                totalDigits++;
            } else {
                while (x) {
                    totalDigits++;
                    x /= 10;
                }
            }
        }


        if (totalDigits > m) {
            cout << "Sasha\n";
        } else {
            cout << "Anna\n";
        }
    }

    return 0;
}

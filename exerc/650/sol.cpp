// #pragma GCC target("popcnt")  // if solution involves bitset
#include <bits/stdc++.h>
using namespace std;

#ifdef croquete  // BEGIN TEMPLATE ----------------------|
#include "dbg.h"
#define fio freopen("in.txt", "r", stdin)
#else
#define dbg(...)
#define fio cin.tie(0)->sync_with_stdio(0)
#endif
#define ll           long long
#define vll          vector<ll>
#define vvll         vector<vll>
#define pll          pair<ll, ll>
#define vpll         vector<pll>
#define all(xs)      xs.begin(), xs.end()
#define rep(i, a, b) for (ll i = (a); i  < (ll)(b); ++i)
#define per(i, a, b) for (ll i = (a); i >= (ll)(b); --i)
#define eb           emplace_back
#define cinj         cin.iword(0)  = 1, cin
#define coutj        cout.iword(0) = 1, cout
template <typename T>  // read vector
istream& operator>>(istream& is, vector<T>& xs) {
    assert(!xs.empty());
    rep(i, is.iword(0), xs.size()) is >> xs[i];
    return is.iword(0) = 0, is;
} template <typename T>  // print vector
ostream& operator<<(ostream& os, vector<T>& xs) {
    rep(i, os.iword(0), xs.size()) os << xs[i] << ' ';
    return os.iword(0) = 0, os;
} void solve();
signed main() {
    fio;
    ll t = 1;
    cin >> t;
    while (t--) solve();
}  // END TEMPLATE --------------------------------------|

class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        return 1 + minStepRec(1, 1, n);
    }
private:
    int minStepRec(int currLength, int pasteLength, int n) {
        if (currLength == n) return 0;

        if (currLength > n) return 1000;

        int copyAllAndPaste = 2 + minStepRec(currLength * 2, currLength, n);
        int paste = 1 + minStepRec(currLength + pasteLength, pasteLength, n);

        return min(copyAllAndPaste, paste);
    }
};

void solve() {
    Solution sol;
    ll n;
    cin >> n;
    cout << sol.minSteps(n) << '\n';
}

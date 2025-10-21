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
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> best;
        int n1 = (int)nums1.size();
        int n2 = (int)nums2.size();
        for (int i = max(0, k - n2); i <= min(k, n1); ++i) {
            vector<int> part1 = pickMax(nums1, i);
            vector<int> part2 = pickMax(nums2, k - i);
            vector<int> candidate = merge(part1, part2);
            if (candidate > best) {
                best = candidate;
            }
        }

        return best;
    }
private:
    vector<int> pickMax(const vector<int>& nums, int k) {
        vector<int> res;
        int drop = (int)nums.size() - k;
        for (int num : nums) {
            while (drop && !res.empty() && res.back() < num) {
                res.pop_back();
                drop--;
            }
            res.push_back(num);
        }
        res.resize(k);
        return res;
    }

    vector<int> merge(const vector<int>& nums1, const vector<int>& nums2) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()) {
            if (lexicographical_compare(nums1.begin() + i, nums1.end(),
                                        nums2.begin() + j, nums2.end())) {
                res.push_back(nums2[j++]);
            } else {
                res.push_back(nums1[i++]);
            }
        }
        return res;
    }
};;

void solve() {
    Solution sol;

    // [3,4,6,5]
    vector<int> nums1 = {3, 4, 6, 5};
    vector<int> nums2 = {9, 1, 2, 5, 8, 3};
    int k = 5;
    vector<int> result = sol.maxNumber(nums1, nums2, k);
    cout << result << '\n';
}

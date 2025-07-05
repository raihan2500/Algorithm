#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define pb push_back

void thikKor(string &a) {
    reverse(all(a));
    while (!a.empty() && a.back() == '0') a.pop_back();
    if (a.empty()) a = "0";
    reverse(all(a));
}

string add(string a, string b) {
    thikKor(a);
    thikKor(b);
    if (a.size() < b.size()) swap(a, b);

    string ans;
    int carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (j >= 0) {
        int sum = (a[i] - '0') + (b[j] - '0') + carry;
        ans.pb((sum % 10) + '0');
        carry = sum / 10;
        i--; j--;
    }

    while (i >= 0) {
        int sum = (a[i] - '0') + carry;
        ans.pb((sum % 10) + '0');
        carry = sum / 10;
        i--;
    }

    if (carry) ans.pb(carry + '0');
    reverse(all(ans));
    thikKor(ans);
    return ans;
}

pair<bool, string> sub(string a, string b) {
    thikKor(a);
    thikKor(b);
    bool neg = false;

    if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
        swap(a, b);
        neg = true;
    }

    string ans;
    int i = a.size() - 1, j = b.size() - 1, borrow = 0;

    while (j >= 0) {
        int x = a[i] - '0';
        int y = b[j] - '0' + borrow;
        if (x < y) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans.pb((x - y) + '0');
        i--; j--;
    }

    while (i >= 0) {
        int x = a[i] - '0' - borrow;
        if (x < 0) {
            x += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        ans.pb(x + '0');
        i--;
    }

    reverse(all(ans));
    thikKor(ans);
    return {neg, ans};
}

void solve() {
    string a, b;
    cin >> a >> b;

    bool af = (a[0] == '-'), bf = (b[0] == '-');
    if (af) a = a.substr(1);
    if (bf) b = b.substr(1);

    if (af == bf) {
        string res = add(a, b);
        if (af && res != "0") cout << "-";
        cout << res << "\n";
    } else {
        pair<bool, string> res;
        if (af) res = sub(b, a); // -a + b
        else res = sub(a, b);    // a + (-b)
        if (res.first && res.second != "0") cout << "-";
        cout << res.second << "\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while (t--) solve();
    return 0;
}

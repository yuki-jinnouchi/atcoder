/**
 * author:  Jini
 * sampled by
 *  https://gist.github.com/yoshihikosuzuki/bbf67915b0920954eb069be3c49b924d
**/

#include <bits/stdc++.h>
using namespace std;

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;
using sts = set<string>;

/* define short */
#define pb push_back
#define mp make_pair
#define all(obj) (obj).begin(), (obj).end()
#define YESNO(bool) if(bool){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define yesno(bool) if(bool){cout<<"yes"<<endl;}else{cout<<"no"<<endl;}
#define YesNo(bool) if(bool){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}

/* REP macro */
#define reps(i, a, n) for (ll i = (a); i < (ll)(n); ++i)
#define rep(i, n) reps(i, 0, n)
#define rrep(i, n) reps(i, 1, n + 1)
#define repd(i,n) for(ll i=n-1;i>=0;i--)
#define rrepd(i,n) for(ll i=n;i>=1;i--)

/* main section */
void solve(ll R){
    ll ans = 0;
    ll double_x, limit, double_limit;
    vll limits;
    ll doible_pow_r = pow(2 * R, 2);
    double_limit = 2 * R;
    rep(i, R){
        double_x = 2 * i + 1;
        while(pow(double_x, 2) + pow(double_limit, 2) > doible_pow_r){
            double_limit--;
        }
        limit = (double_limit + 1) / 2;
        limits.pb(limit);
    }
    rep(i, R){
        if (i == 0){
            if (limits[i] >= 1)
                ans += 1;
        } else {
            ans += limits[i] * 4;
        }
    }
    cout << ans << endl;
}

int main(){
    ll R;
    cin >> R;
    solve(R);
    return 0;
}

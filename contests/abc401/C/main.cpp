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
void solve(ll N, ll K) {
    vll A(N+1, 0);
    ll sum = 0;
    ll ans = 1;
    rep(i, N + 1){
        // cout << "i: " << i << " Before sum: " << sum << " ans: " << ans;
        if (i < K){
            ans = 1;
            sum ++;
        } else {
            if (i != K){
                sum += A[i - 1];
                sum -= A[i - K - 1];
            }
            ans = sum;
        }
        ans %= (ll) 1e9;
        A[i] = ans;
        // cout << " After sum: " << sum << " ans: " << ans << endl;
    }
    cout << ans << endl;
}

int main(){
    ll N, K;
    cin >> N >> K;
    solve(N, K);
    return 0;
}

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

void solve(int N, int R, vvi DA){
    int ans = R;
    rep(i, N){
        if(DA[i][0] == 1){
            if (1600 <= ans && ans <= 2799)
            ans += DA[i][1];
        }else if(DA[i][0] == 2){
            if (1200 <= ans && ans <= 2399)
            ans += DA[i][1];
        }
    }
    cout << ans << endl;
}

/* main section */
int main(){
    int N, R;
    cin >> N >> R;
    vvi DA(N, vi(2));
    rep(i, N){
        cin >> DA[i][0] >> DA[i][1];
    }
    solve(N, R, DA);
    return 0;
}

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

void solve(ll N, ll M, vvll XA){
    sort(all(XA));
    ll x_cnt = 0;
    ll x_sum = 0;
    ll sum_opr = 0;
    rep(i, N){
        // cout << "i: " << i;
        if (x_cnt < M && XA[x_cnt][0] == i + 1){
            x_sum += XA[x_cnt][1];
            if (x_cnt < M-1){
                x_cnt++;
            }
        }
        // cout << " x_sum: " << x_sum;
        x_sum--;
        // cout << " x_sum: " << x_sum;
        if (x_sum < 0){
            cout << -1 << endl;
            return;
        }
        sum_opr += x_sum;
        // cout << " sum_opr: " << sum_opr;
        // cout << endl;
    }
    if (x_sum != 0){
        cout << -1 << endl;
        return;
    }
    cout << sum_opr << endl;
    return;
}

int main(){
    ll N, M;
    cin >> N >> M;
    vvll XA(M, vll(2));
    rep(i, M){
        cin >> XA[i][0];
    }
    rep(i, M){
        cin >> XA[i][1];
    }
    solve(N, M, XA);
    return 0;
}

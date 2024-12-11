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

void solve(ll N, ll M, vll A, vll B, ll MX){
    vll C(MX + 1, 0);
    int i, j;
    i = MX;
    j = 0;
    while (0 < i){
        while (i < A[j] && j < N && j != -2){
            j++;
        }
        if (N <= j){
            j = -2;
        }
        C[i] = j + 1;
        i--;
    }
    rep(a, M){
        if (B[a] > MX){
            cout << 1 << endl;
        }
        else
            cout << C[B[a]] << endl;
    }
}

/* main section */
int main(){
    ll N, M, MX;
    cin >> N >> M;
    MX = 1;
    vll A(N), B(M);
    rep(i, N){
        cin >> A[i];
        MX = max(MX, A[i]);
    }
    rep(i, M){
        cin >> B[i];
    }
    solve(N, M, A, B, MX);
    return 0;
}

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
void solve(ll N, vvll query){
    vector<set<ll>> rights(N, set<ll>());
    ll num, X, Y;
    rep(i, query.size()){
        num = query[i][0];
        X = query[i][1] - 1;
        if (num == 1 || num == 3) {
            Y = query[i][2];
        }

        if (num == 1)
            rights[X].insert(Y);
        else if (num == 2)
            rights[X].insert(0);
        else if (num == 3) {
            if (rights[X].find(0) != rights[X].end())
                cout << "Yes" << endl;
            else if (rights[X].find(Y) != rights[X].end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
}

int main(){
    ll N, M, Q;
    cin >> N >> M >> Q;
    vvll query(Q, vll(3, 0));
    rep(i, Q){
        cin >> query[i][0];
        if (query[i][0] == 1 || query[i][0] == 3) {
            cin >> query[i][1] >> query[i][2];
        } else {
            cin >> query[i][1];
        }
    }
    solve(N, query);
    return 0;
}

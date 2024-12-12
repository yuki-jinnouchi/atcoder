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
void solve(string S, string T){
    vvi Sv, Tv;
    rep(i, S.size()){
        if (i == 0 || S[i] != S[i-1]){
            Sv.pb({S[i], 1});
        }else{
            Sv.back()[1]++;
        }
    }
    rep(i, T.size()){
        if (i == 0 || T[i] != T[i-1]){
            Tv.pb({T[i], 1});
        }else{
            Tv.back()[1]++;
        }
    }
    if (Sv.size() != Tv.size()){
        cout << "No" << endl;
        return;
    }
    rep(i, Sv.size()){
        if (Sv[i][0] != Tv[i][0] || (Sv[i][1] == 1 && Tv[i][1] > 1) || (Sv[i][1] > Tv[i][1])){
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
    return;
}

int main(){
    string S;
	cin >> S;
	string T;
	cin >> T;
    solve(S, T);
    return 0;
}
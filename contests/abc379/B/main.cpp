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

void solve(ll N, ll K, string S){
    ll all_count = 0;
    ll char_count;

    ll i = 0;
    char_count = 0;
    while (i < N){
        if (S[i] != 'X'){
            char_count++;
            // cout << "chr_count: " << char_count << endl;
            if (char_count == K){
                all_count++;
                char_count = 0;
            }
        }else{
            char_count = 0;
        }
        // cout << "i: " << i << " char_count: " << char_count << " all_count: " << all_count << endl;
        i++;
    }
    cout << all_count << endl;
}

int main(){
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    solve(N, K, S);
    return 0;
}

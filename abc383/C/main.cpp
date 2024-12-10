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

void print(vvi vec){
    rep(i, vec.size()){
        rep(j, vec[i].size()){
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vvi rewrite(vvi S, int D){
    rep(i, S.size()){
        rep(j, S[i].size()){
            if(S[i][j] == D){
                if(0 < i && -1 <= S[i-1][j] && S[i-1][j] < D){
                    S[i-1][j] = D - 1;
                }
                if(i < (ll) S.size() - 1 && -1 <= S[i+1][j] && S[i+1][j] < D){
                    S[i+1][j] = D - 1;
                }
                if(0 < j && -1 <= S[i][j-1] && S[i][j-1] < D){
                    S[i][j-1] = D - 1;
                }
                if(j < (ll) S[i].size() - 1 && -1 <= S[i][j+1] && S[i][j+1] < D){
                    S[i][j+1] = D - 1;
                }
            }
        }
    }
    return S;
}

void solve(int H, int W, int D, vvi S){
    // print(S);
    rep(i, D){
        S = rewrite(S, D - i);
        // print(S);
    }

    int ans = 0;
    rep(i, H){
        rep(j, W){
            if (S[i][j] >= 0){
                ans++;
            }
        }
    }
    cout << ans << endl;
}

/* main section */
int main(){
    int H, W, D;
    cin >> H >> W >> D;

    string str;
    vvi vec(H, vi(W, 0));
    vi line(W);
    rep(i, H){
        cin >> str;
        rep(j, W){
            if (str[j] == '#'){
                line[j] = -2;
            }
            else if(str[j] == '.'){
                line[j] = -1;
            }
            else if(str[j] == 'H'){
                line[j] = D;
            }
        }
        vec[i] = line;
    }
    solve(H, W, D, vec);
    return 0;
}

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
void solve(int H, int W, int X, int Y, vector<string> S, string T){
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int count = 0;
    int x, y, nx, ny;
    x = X - 1;
    y = Y - 1 ;
    set <pair<int, int>> st;
    rep(i, T.size()){
        if (T[i] == 'U'){
            nx = x + dx[0];
            ny = y + dy[0];
        } else if (T[i] == 'D'){
            nx = x + dx[1];
            ny = y + dy[1];
        } else if (T[i] == 'L'){
            nx = x + dx[2];
            ny = y + dy[2];
        } else if (T[i] == 'R'){
            nx = x + dx[3];
            ny = y + dy[3];
        } else {
            nx = x;
            ny = y;
        }
        // cout << nx + 1 << ' '  << ny + 1 << ' ';
        if (nx < 0 || nx >= H || ny < 0 || ny >= W || S[nx][ny] == '#'){
            // cout << -1 << endl;
            continue;
        } else if (S[nx][ny] == '.' || S[nx][ny] == '@'){
            if (S[nx][ny] == '@' && st.find(make_pair(nx, ny)) == st.end()){
                st.insert(make_pair(nx, ny));
                count++;
            }
            x = nx;
            y = ny;
            // cout << count << endl;
            continue;
        }
    }
    cout << x + 1 << " " << y + 1 << " " << count << endl;
}

int main(){
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    vector<string> S(H);
    rep(i, H) cin >> S[i];
    string T;
    cin >> T;
    solve(H, W, X, Y, S, T);
    return 0;
}

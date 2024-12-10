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

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
// const int INF = 1e9;

void solve(int H, int W, int D, vvi vec, queue<vi> que){
    vi now;
    int x, y, nx, ny;

    while(!que.empty()){
        now = que.front();
        que.pop();
        x = now[0];
        y = now[1];
        rep(i, 4){
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= H || ny < 0 || ny >= W){
                continue;
            }
            if (vec[nx][ny] == -1 || vec[nx][ny] > vec[x][y] + 1){
                vec[nx][ny] = vec[x][y] + 1;
                que.push({nx, ny});
            }
        }
    }

    int ans = 0;
    rep(i, H){
        rep(j, W){
            if (0 <= vec[i][j] && vec[i][j] <= D){
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

    vvi vec(H, vi(W, 0));
    vi line(W);
    string str;

    vi start(2);
    queue<vi> que;

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
                line[j] = 0;
                start = {(int) i, (int) j};
                que.push(start);
            }
        }
        vec[i] = line;
    }
    solve(H, W, D, vec, que);
    return 0;
}

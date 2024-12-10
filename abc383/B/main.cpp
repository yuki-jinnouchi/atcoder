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

#define abs(x) ((x) >= 0 ? (x) : -(x))

int count_humid(int H, int W, int D, vs S, int a, int b){
    int ans = 0;

    int a_y = a / W;
    int a_x = a % W;
    int b_y = b / W;
    int b_x = b % W;
    if (S[a_y][a_x] == '#' || S[b_y][b_x] == '#'){
        return 0;
    }

    int dist_a, dist_b;
    rep(i, H){
        rep(j, W){
            dist_a = abs(a_x - j) + abs(a_y - i);
            dist_b = abs(b_x - j) + abs(b_y - i);
            if (S[i][j] == '.' && (dist_a <= D || dist_b <= D)){
                ans++;
            }
        }
    }
    return ans;
}

void solve(int H, int W, int D, vs S){
    int ans = 0;
    int a, b;

    a = 0;
    while(a < (H * W) - 1){
        b = 1;
        while((a + b) < (H * W)){
            ans = max(ans, count_humid(H, W, D, S, a, a + b));
            b++;
        }
        a++;
    }
    cout << ans << endl;
}

/* main section */
int main(){
    int H, W, D;
    cin >> H >> W >> D;
    vs S(H);
    rep(i, H){
        cin >> S[i];
    }
    solve(H, W, D, S);
    return 0;
}

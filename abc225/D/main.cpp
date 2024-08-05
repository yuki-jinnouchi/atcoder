/**
 * author:  Jini
 * create-mm-dd hh:mm:ss
 * sampled by
 *  https://gist.github.com/yoshihikosuzuki/bbf67915b0920954eb069be3c49b924d
**/

#include <bits/stdc++.h>
using namespace std;

// clang-format off
/* accelration */
// 高速バイナリ生成
// #pragma GCC target("avx")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化)
// cとstdの入出力を混在させるとバグるので注意
// struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;

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

/* debug */
// 標準エラー出力を含む提出はrejectされる場合もあるので注意
#define debug(x) cerr << "\033[33m(line:" << __LINE__ << ") " << #x << ": " << x << "\033[m" << endl;

/* func */
inline int in_int() {int x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline string in_str() {string x; cin >> x; return x;}
// search_length: 走査するベクトル長の上限(先頭から何要素目までを検索対象とするか、1始まりで)
template <typename T> inline bool vector_finder(std::vector<T> vec, T element, unsigned int search_length) {
    auto itr = std::find(vec.begin(), vec.end(), element);
    size_t index = std::distance( vec.begin(), itr );
    if (index == vec.size() || index >= search_length) {return false;} else {return true;}
}
template <typename T> inline void print(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
template <typename T, typename S> inline void print(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void print(const T& x) {cout << x << "\n";}
template <typename T, typename S> inline void print(const vector<pair<T, S>>& v)
    {for (auto&& p : v) print(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
// gcd lcm
// C++17からは標準実装
// template <typename T> T gcd(T a, T b) {if (b == 0)return a; else return gcd(b, a % b);}
// template <typename T> inline T lcm(T a, T b) {return (a * b) / gcd(a, b);}
// clang-format on

// グリッド探索問題
// def check(p,q): return 0<=p<H and 0<=q<W and C[p][q]=='.'
// bool out_grid(ll i, ll j, ll h, ll w) { return (!(0 <= i && i < h && 0 <= j && j < w));}

void solve(int N, int Q, vvi query){
    vi front(N, -1), back(N, -1);
    int tmp_front = -1;
    int tmp_back = -1;
    rep(i, Q){
        if (query[i][0] == 1){
            front[query [i][2] - 1] = query[i][1];
            back[query[i][1] - 1] = query[i][2];
        }
        else if (query[i][0] == 2){
            front[query[i][2] - 1] = -1;
            back[query[i][1] - 1] = -1;
        }
        else if (query[i][0] == 3){
            tmp_front  = query[i][1];
            vi ans = {tmp_front};
            while(tmp_front != -1){
                tmp_front = front[tmp_front - 1];
                if (tmp_front != -1)
                    ans.insert(ans.begin(), tmp_front);
            }
            tmp_back = query[i][1];
            while(tmp_back != -1){
                tmp_back = back[tmp_back - 1];
                if (tmp_back != -1)
                    ans.push_back(tmp_back);
            }

            std::cout << ans.size();
            rep(i, ans.size())
                std::cout << " "<< ans[i];
            std::cout << endl;
        }
    }
    return;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    vvi query(Q, vi(3, 0));
    rep(i, Q) {
        cin >> query[i][0];
        if (query[i][0] != 3){
            cin >> query[i][1] >> query[i][2];
        }
        else
            cin >> query[i][1];
    }
    solve(N, Q, query);
    return 0;
}

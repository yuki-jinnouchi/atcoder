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
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
// cin cout の結びつけ解除, stdioと同期しない(入出力非同期化)
// cとstdの入出力を混在させるとバグるので注意
struct Fast {Fast() {std::cin.tie(0); ios::sync_with_stdio(false);}} fast;

/* alias */
using ull = unsigned long long;
using ll = long long;
using vi = vector<long>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<long, long>;

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
inline long in_long() {long x; cin >> x; return x;}
inline ll in_ll() {ll x; cin >> x; return x;}
inline string in_str() {string x; cin >> x; return x;}
// search_length: 走査するベクトル長の上限(先頭から何要素目までを検索対象とするか、1始まりで)
template <typename T> inline bool vector_finder(std::vector<T> vec, T element, unsigned long search_length) {
    auto itr = std::find(vec.begin(), vec.end(), element);
    size_t index = std::distance( vec.begin(), itr );
    if (index == vec.size() || index >= search_length) {return false;} else {return true;}
}
template <typename T> inline void prlong(const vector<T>& v, string s = " ")
    {rep(i, v.size()) cout << v[i] << (i != (ll)v.size() - 1 ? s : "\n");}
template <typename T, typename S> inline void prlong(const pair<T, S>& p)
    {cout << p.first << " " << p.second << endl;}
template <typename T> inline void prlong(const T& x) {cout << x << "\n";}
template <typename T, typename S> inline void prlong(const vector<pair<T, S>>& v)
    {for (auto&& p : v) prlong(p);}
// 第一引数と第二引数を比較し、第一引数(a)をより大きい/小さい値に上書き
template <typename T> inline bool chmin(T& a, const T& b) {bool compare = a > b; if (a > b) a = b; return compare;}
template <typename T> inline bool chmax(T& a, const T& b) {bool compare = a < b; if (a < b) a = b; return compare;}
// gcd lcm
// C++17からは標準実装
// template <typename T> T gcd(T a, T b) {if (b == 0)return a; else return gcd(b, a % b);}
// template <typename T> inline T lcm(T a, T b) {return (a * b) / gcd(a, b);}
// clang-format on

const string YES = "Yes";
const string NO = "No";

vvi calc (long N, vvi T){
    vvi S(N, vi(5));
    rep(i, N){
        S[i][0] = T[i][0]; // index
        S[i][1] = T[i][1]; // min
        S[i][2] = T[i][2]; // max
        S[i][3] = S[i][1];
    }
    return S;
}

long calc_sum(long N, vvl S){
    long sum = 0;
    rep(i, N)
        sum += S[i][3];
    return sum;
}

vvl adjust(long N, vvl S){
    long sum = calc_sum(N, S);
    long i = 0;
    while (sum < 0 && i < N)
    {
        while(sum < 0 && S[i][3] < S[i][2])
        {
            long diff = S[i][2] - S[i][3];
            if (S[i][2] - S[i][3] < -sum)
            {
                S[i][3] = S[i][2];
                sum += diff;
            }
            else
            {
                S[i][3] += -sum;
                sum = 0;
            }
        }
        i++;
    }
    return S;
}

void solve(long N, vvi T){
    vvl S(N, vl(4));
    vvl S2(N, vl(4));
    S = calc(N, T);
    S2 = adjust(N, S);
    long ans = calc_sum(N, S2);
    if (ans == 0)
    {
        cout << "Yes" << endl;
        rep(i, N)
            cout << S2[i][3] << ' ';
        cout << endl;
    }
    else
    {
        cout << "No" << endl;
        // cout << ans << endl;
    }
    return ;
}

int main(){
    long N;
    cin >> N;
    vvl T(N, vi(3));
    rep(i, N)
    {
        T[i][0] = i;
        cin >> T[i][1] >> T[i][2];
    }
    solve(N, T);
    return 0;
}

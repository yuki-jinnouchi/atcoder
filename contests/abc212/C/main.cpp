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
using vi = vector<int>;
using vl = vector<long>;
using vll = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
using vvll = vector<vll>;
using vs = vector<string>;
using pii = pair<int, int>;

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



/* main section */
void solve(long long N, long long M, std::vector<long long> A, std::vector<long long> B)
{
	vector<vector<ll>> X(N+M, vector<ll>(2));
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	ll j = 0;
	ll k = 0;

	ll ans = -1;
	ll diff = 0;

	rep(i, N + M)
	{
		if ((A[j]<B[k] || k == M) && j != N)
		{
			X[i][0] = A[j];
			X[i][1] = 0;
			j++;
		}
		else
		{
			X[i][0] = B[k];
			X[i][1] = 1;
			k++;
		}

		// fprintf(stderr, "X[%d]: %d %d, j = %d k = %d\n", i, X[i][0], X[i][1], j, k);
	}

	rep(i2, N + M - 1)
	{
		diff = X[i2+1][0] - X[i2][0];
		// fprintf(stderr,"X[%d]: %d %d, ans = %d diff = %d\n", i2, X[i2][0], X[i2][1], ans, diff);
		// fprintf(stderr, "%d %d %d\n", X[i2][1] != X[i2+1][1], ans = -1, diff < ans);
		if (X[i2][1] != X[i2+1][1] && (ans == -1 || diff < ans))
			ans = diff;
		// fprintf(stderr, "ans = %d\n", ans);
	}
	cout << ans << endl;
	return ;
}

int main(){
    long long N;
	std::scanf("%lld", &N);
	long long M;
	std::scanf("%lld", &M);
	std::vector<long long> A(N);
	for(int i = 0 ; i < N ; i++){
		std::scanf("%lld", &A[i]);
	}
	std::vector<long long> B(M);
	for(int i = 0 ; i < M ; i++){
		std::scanf("%lld", &B[i]);
	}
    solve(N, M, std::move(A), std::move(B));
    return 0;
}

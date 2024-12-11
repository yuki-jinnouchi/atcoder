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

const string YES = "Yes";
const string NO = "No";

int is_same_number(long long N, vector<string> S, vector<string> T)
{
    int n_S = 0;
    int n_T = 0;

    rep(i, N)
    {
        rep(j, N)
        {
			if (S[i][j] == '#')
                n_S++;
            if (T[i][j] == '#')
                n_T++;
        }
    }
    if (n_S != n_T)
        return (-1);
    return (n_S);
}

int count_sharpS(int N, int diff_x, int diff_y, vector<string> S)
{
    int n_S = 0;

    rep(i, N - diff_y)
    {
        rep(j, N - diff_x)
        {
			if (S[i + diff_y][j + diff_x] == '#')
                n_S++;
        }
    }
    return (n_S);
}

int count_sharpT(int N, int diff_x, int diff_y, vector<string> S)
{
    int n_S = 0;

    rep(i, N - diff_y)
    {
        rep(j, N - diff_x)
        {
			if (S[i][j] == '#')
                n_S++;
        }
    }
    return (n_S);
}


/* main section */
void solve(long long N, vector<string> S, vector<string> T){

    int n = 0;

    n = is_same_number(N, S, T);
    if (n == -1)
    {
        cout << NO << endl;
        return;
    }

    int count_a , count_b , count_c , count_d;
	int count_e , count_f , count_g , count_h;
    int diff_x = 0;
    int diff_y = 0;

    rep(diff, N * N)
    {
        diff_x = diff % N;
        diff_y = diff / N;

		if (n <= (N - diff_x) * (N - diff_y) && \
			(count_sharpT(N, diff_x, diff_y, T) == n || count_sharpS(N, diff_x, diff_y, T) == n))
		{

			count_a = 0;
			count_b = 0;
			count_c = 0;
			count_d = 0;

			count_e = 0;
			count_f = 0;
			count_g = 0;
			count_h = 0;

			rep(i, N - diff_y)
			{
				rep(j, N - diff_x)
				{
					if (S[i][j] == '#' && T[i + diff_y][j + diff_x] == '#')
						count_a ++;
					if (S[j][(N - 1) - i] == '#' && T[i + diff_y][j + diff_x] == '#')
						count_b ++;
					if (S[(N - 1) - i][(N - 1) - j] == '#' && T[i + diff_y][j + diff_x] == '#')
						count_c ++;
					if (S[(N - 1) - j][i] == '#' && T[i + diff_y][j + diff_x] == '#')
						count_d ++;
					if (S[i + diff_y][j + diff_x] == '#' && T[i][j] == '#')
						count_e ++;
					if (S[j + diff_x][((N - 1) - (i + diff_y))] == '#' && T[i][j] == '#')
						count_f ++;
					if (S[((N - 1) - (i + diff_y))][((N - 1) - (j + diff_x))] == '#' && T[i][j] == '#')
						count_g ++;
					if (S[((N - 1) - (j + diff_x))][i + diff_y] == '#' && T[i][j] == '#')
						count_h ++;
				}
			}
			if (count_a == n || count_b == n || count_c == n || count_d == n || \
				count_e == n || count_f == n || count_g == n || count_h == n)
			{
				cout << YES << endl;
				return;
			}
		}
    }
    cout << NO << endl;
    return;
}

int main(){
    long long N;
	cin >> N;
	vector<string> S(N);
	for(int i = 0 ; i < N ; i++){
		cin >> S[i];
	}
	vector<string> T(N);
	for(int i = 0 ; i < N ; i++){
		cin >> T[i];
	}
    solve(N, move(S), move(T));
    return 0;
}

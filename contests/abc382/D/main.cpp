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

ull factorial(int n) {
    ull result = 1;
    while (n > 1) {
        result *= n;
        n--;
    }
    return result;
}

ull factorial2(int n, int m) {
    ull result = 1;
    while (n > m) {
        result *= n;
        n--;
    }
    return result;
}

void show(vi A){
    rep(i, A.size()){
        cout << A[i];
        if (i < (ll) A.size() - 1)
            cout << " ";
        else
            cout << endl;
    }
}

void rec(int N, int M, vi A, int i, int x)
{
    int j = 0;
    while(j <= x)
    {
        if (i == 0)
            A[i] = 1 + j;
        else
            A[i] =  A[i - 1] + 10 + j;
        if (i < N - 1)
            rec(N, M, A, i + 1, x - j);
        else if (A[i] <= M)
            show(A);
        j++;
    }
}

void solve(int N, int M){
    int x = M - (10 * (N - 1) + 1);
    // ull y = factorial(x + N) / (factorial(x) * factorial(N));
    ull y = factorial2(x + N, x) / factorial(N);
    cout << y << endl;
    vi A(N, 0);
    rec(N, M, A, 0, x);
}

/* main section */
int main(){
    int N, M;
    cin >> N >> M;
    solve(N, M);
    return 0;
}

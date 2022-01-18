#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef string str;

typedef pair<int, int>      pi;
typedef pair<ll, ll>        pl;
typedef pair<ull, ull>     pul;
typedef pair<ld, ld>       pld;
typedef pair<double,double> pd;

typedef vector<int>    vi;
typedef vector<ll>     vl;
typedef vector<ull>   vul;
typedef vector<bool>   vb;
typedef vector<double> vd;
typedef vector<ld>    vld;
typedef vector<str>    vs;

typedef vector<pi>    vpi;
typedef vector<pl>    vpl;
typedef vector<pul>  vpul;
typedef vector<pld>  vpld;
typedef vector<pd>    vpd;

typedef vector<vi>    vvi;
typedef vector<vl>    vvl;  

#define mp  make_pair
#define pb  push_back
#define F   first
#define S   second
#define lb  lower_bound
#define ub  upper_bound
#define ins insert

#define rsz resize
#define sz(x) (int)x.size()
#define beg(x) x.begin()
#define en(x) x.end()
#define all(x) beg(x), en(x)
#define rall(x) x.rbegin(), x.rend()
#define sortall(x) sort(all(x))

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) F0R(_,a)
#define each(a,x) for (auto& a: x)
#define tr(it, x) for(auto it = beg(x); it != en(x); it++)

#define clr(x,i) memset(x, i, sizeof(x))

#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x <<": "; _print(x); cerr << "\n";
#define dnl(x) cerr <<"----------- Test Case # " << x << " -----------\n";
#else
#define dbg(x)
#define dnl(x)
#endif

void _print(ll t);
void _print(int t);
void _print(str t);
void _print(char t);
void _print(ld t);
void _print(double t);
void _print(ull t);

template <class T, class V> void _print(pair <T, V> &p);
template <class T> void _print(vector <T> &v);
template <class T> void _print(set <T> &v);
template <class T, class V> void _print(map <T, V> &v);
template <class T> void _print(multiset <T> &v);

int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int MOD = 1'000'000'007;
const int INF = 2e9;
const int N = 3e5, M = N;
//=======================

vvi g(N);

void solve() {
  int n,m,k;
  cin>>n>>m>>k;
  int cards_per_player = n/k;
  int winner_jokers = min(m,cards_per_player);
  int rem_jokers = m - winner_jokers;
  int x = (rem_jokers + (k-1) - 1)/(k-1);
  cout<< winner_jokers - x << "\n";
}

inline namespace FileIO {
  void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
  void setOut(str s) { freopen(s.c_str(),"w",stdout); }
  void setErr()      { freopen("Error.out","w",stderr); }
  void setIO(str s = "") {
    cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
    // cin.exceptions(cin.failbit);
    // throws exception when do smth illegal
    // ex. try to read letter into int
    if (sz(s)) setIn(s+".in"), setOut(s+".out"); // for old USACO
    #ifndef ONLINE_JUDGE
      setErr();
    #endif
  }
}

int main() {
    setIO();
    int t = 1;
    cin >> t;
    F0R(i,t) {
      dnl(i+1);
      solve();
    }
    return 0;
}

int mpow(int base, int exp) {
  base %= MOD;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % MOD;
    base = ((ll)base * base) % MOD;
    exp >>= 1;
  }
  return result;
}

void ipgraph(int n, int m){
	int i, u, v;
	while(m--){
		cin>>u>>v;
    u--, v--;
		g[u].pb(v);
		g[v].pb(u);
	}
}

void dfs(int u, int par){
	for(int v:g[u]){
		if (v == par) continue;
		dfs(v, u);
	}
}

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(str t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> &p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> &v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> &v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> &v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> &v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
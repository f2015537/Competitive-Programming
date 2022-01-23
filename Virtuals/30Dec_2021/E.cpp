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
#define tr(it, x) for(auto it = beg(x); it != en(x); ++it)

#define clr(x,i) memset(x, i, sizeof(x))

// ************************DEBUG START********************************
#ifdef chemecocs
// #define cerr cout  // if you want to print to stdout, uncomment this
template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  return os << '{' << p.first << ", " << p.second << '}';
}

template <class T, class = decay_t<decltype(*begin(declval<T>()))>,
          class = enable_if_t<!is_same<T, string>::value>>
ostream &operator<<(ostream &os, const T &c) {
  os << '[';
  tr(it,c)
    os << &", "[2 * (it == beg(c))] << *it;
  return os << ']';
}
//support up to 5 args
#define _NTH_ARG(_1, _2, _3, _4, _5, _6, N, ...) N
#define _FE_0(_CALL, ...)
#define _FE_1(_CALL, x) _CALL(x)
#define _FE_2(_CALL, x, ...) _CALL(x) _FE_1(_CALL, __VA_ARGS__)
#define _FE_3(_CALL, x, ...) _CALL(x) _FE_2(_CALL, __VA_ARGS__)
#define _FE_4(_CALL, x, ...) _CALL(x) _FE_3(_CALL, __VA_ARGS__)
#define _FE_5(_CALL, x, ...) _CALL(x) _FE_4(_CALL, __VA_ARGS__)
#define FOR_EACH_MACRO(MACRO, ...)                                             \
  _NTH_ARG(dummy, ##__VA_ARGS__, _FE_5, _FE_4, _FE_3, _FE_2, _FE_1, _FE_0)     \
  (MACRO, ##__VA_ARGS__)
//Change output format here
#define out(x) #x " = " << x << "; "
#define dbg(...)                                                              \
  cerr << __func__ << ":" << __LINE__ << ": " FOR_EACH_MACRO(out, __VA_ARGS__) << "\n"
#define dnl(x) cerr <<"----------- Test Case # " << x << " -----------\n";
#else
#define dbg(...)
#define dnl(x)
#endif
// ************************DEBUG END**********************************

int mpow(int base, int exp); 
void ipgraph(int n, int m);
void dfs(int u, int par);

const int MOD = 1'000'000'007;
const int INF = 2e9;
const int N = 3e5, M = N;
//=======================

vvi g(N);
vi v(N);

void solve() {
  ll n,k;
  cin>>n>>k;

  vl v(n);

  each(x,v) cin>>x;
  ll temp = v[0];
  for(int i = 1; i < n; ++i){
    ll sum = 0;
    for(int j = 0; j < i; ++j){
      sum += v[j];
    }

    //find the lowest x for which (sum+x)*k >= v[i]*100
    ll lo = 0, hi = 1e15;
    while(hi - lo > 1){
      ll mid = (lo+hi)>>1;
      if((sum+mid)*k >= v[i]*100LL){
        hi = mid;
      }
      else{
        lo = mid+1;
      }
    }
    ll x;
    if((sum+lo)*k >= v[i]*100LL)  x = lo;
    else x = hi;
    v[0] += x;
  }
  cout<<v[0]-temp<<"\n";
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
    #ifdef chemecocs
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
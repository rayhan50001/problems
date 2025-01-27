//kruskal(MST)
#include<iostream>
#include<cstdio>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>
#include<deque>
#include<iterator>
#include<assert.h>
#include<bitset>
#include<climits>
#include<ctime>
#include<complex>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
//define for shortcut
#define mem(a) memset(a,0,sizeof(a))
#define all(a) a.begin(),a.end()
#define sz(A) A.size()
#define clr(a) memset(a,0,sizeof(a))
#define pb push_back
#define pi acos(-1.0)
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define vpii vector< pair<int,int> >
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define pis pair<int,string>
#define psi pair<string,int>
#define vs vector<string>
#define vi vector<int>
#define vc vector<char>
#define sts set<string>
#define sti set<int>
#define stc set<char>
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define ull unsigned long long
#define ll long long
#define for1(i,a,b) for(int i=a;i<=b;i++)
#define rfor1(i,a,b) for(int i=a;i>=b;i--)
#define rfor0(i,a,b) for(int i=a-1;i>b;i--)
#define for0(i,a) for(int i=0;i<a;i++)
//read input
#define sf(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d%d",&a,&b)
#define sf3(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define sfll2(a,b) scanf("%lld%lld",&a,&b)
#define sfll3(a,b,c) scanf("%lld%lld%lld",&a,&b,&c)
#define ss(a) scanf("%s",&a)
#define sc(a) scanf("%c",&a)
#define sd(a) scanf("%lf",&a)
#define pf(a) printf("%d",a)
#define pfll(a) printf("%lld",a)
#define pfd(a) printf("%.17f",a)
#define pc(a) printf("%c",a)
#define ps(a) printf("%s",a)
#define cs printf("Case %d: ",kk++)
#define cn printf("Case %d:\n",kk++)
///#define c# printf("Case #%d: ",kk++)
#define Mid(l,r) (l+(r-l)>>1)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1000000007
#define inf INT_MAX
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define fast ios_base::sync_with_stdio(false);
int power(int x, unsigned int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = res*x;
        y = y>>1;
        x = x*x;
    }
    return res;
}
template<typename T>inline string tostring(T a)
{
    ostringstream os("");
    os << a;
    return os.str();
}
template<typename T>inline ll tolong(T a)
{
    ll res;
    istringstream os(a);
    os>>res;
    return res;
}
template<typename T>inline vi parse(T str)
{
    vi res;
    int s;
    istringstream os(str);
    while(os>>s)res.pb(s);
    return res;
}
ll SQRT(ll n)
{
    ll e=sqrt(n*1.0);
    ll l=max(0LL,e-2),r=min(n,e+2);
    ll ans=0;
    while(l<=r)
    {
        ll m=Mid(l,r);
        if(m*m<=n)ans=m,l=m+1;
        else r=m-1;
    }
    return ans;
}
ll CBRT(ll n)
{
    ll e=cbrt(n*1.0);
    ll l=max(0LL,e-2),r=min(n,e+2);
    ll ans=0;
    while(l<=r)
    {
        ll m=Mid(l,r);
        if(m*m*m<=n)ans=m,l=m+1;
        else r=m-1;
    }
    return ans;
}
template< class T > inline T _bigmod(T n,T m)
{
    T ans=1,mult=n%mod;
    while(m)
    {
        if(m & 1) ans=(ans*mult)%mod;
        m>>=1;
        mult=(mult*mult)%mod;
    }
    ans%=mod;
    return ans;
}
template< class T > inline T _modinv(T x)
{
    return _bigmod(x,(T) mod-2)%mod;
}
inline int len(string a)
{
    return a.length();
}
inline int len(char a[])
{
    return strlen(a);
}
template<class T> inline T _gcd(T a, T b)
{
    return (b==0) ? a : _gcd(b, a % b);
}
template< class T > inline T _lcm(T x,T y)
{
    return x*y/_gcd(x,y);
}
inline void fastIn(int &num)            // Fast IO, with space and new line ignoring
{
    bool neg = false;
    register int c;
    num = 0;
    c = getchar();
    for( ; c != '-' && (c < '0' || c > '9'); c = getchar());
    if (c == '-')
    {
        neg = true;
        c = getchar();
    }
    for(; (c>47 && c<58); c=getchar())
        num = (num<<1) + (num<<3) + c - 48;
    if(neg)
        num *= -1;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]= {1,1,0,-1,-1,-1,0,1};
//int dy[]= {0,1,1,1,0,-1,-1,-1}; //8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//int EQ(double d) {
//    if ( fabs(d) < EPS ) return 0;
//    return d > EPS ? 1 : -1 ;
//}
int par[1000001];
struct edge{
    int u,v;
    double w;
}graph[1000001];
void init(int n)
{
    for(int i=0; i<=n; i++)par[i]=i;
}
int Find(int x)
{
    if(x==par[x])return x;
    return par[x]=Find(par[x]);
}
void Union(int x,int y)
{
    int xx=Find(x);
    int yy=Find(y);
    if(xx!=yy)
    {
        par[xx] = yy;
    }
}
int cmp(const void *i, const void *j) {
	edge *a, *b;
	a = (edge *)i, b = (edge *)j;
	return a->w - b->w;
}
int main()
{
    clock_t begin = clock();
    //    //your code goes here
    int pp=1;
    int n;
    while(sf(n)==1)
    {
    init(n);
    if(pp++>1)nl;
    int sum=0;
    for(int i=1; i<n; i++)
    {
        int u,v,w;
        sf3(u,v,w);
        sum+=w;
    }
    pf(sum);
    nl;
    int k;
    sf(k);
    for(int i=0; i<k; i++)
    {
         int u,v,w;
         sf3(u,v,w);
         graph[i].u=u;
         graph[i].v=v;
         graph[i].w=w;
    }
    int m;
    sf(m);
    int len=m+k;
    int p=k;
    for(int i=0; i<m; i++)
    {
         int u,v,w;
         sf3(u,v,w);
         graph[p].u=u;
         graph[p].v=v;
         graph[p].w=w;
         p++;
    }
    qsort(graph, len, sizeof(edge), cmp);
    int sum1=0;
    for(int i=0; i<len; i++)
    {
        int xx=Find(graph[i].u);
        int yy=Find(graph[i].v);
        if(xx!=yy)
        {
            Union(graph[i].u,graph[i].v);
            sum1+=graph[i].w;
        }
    }
    pf(sum1);
    nl;
    }
    //    //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}


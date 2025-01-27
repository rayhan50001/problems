//                            ببِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم
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
#define c# printf("Case #%d: ",kk++)
#define nl printf("\n")
#define done cout<<"done"<<endl;
#define eps 1e-9
#define mod 1000000007
#define inf INT_MAX
#define MX 100010
#define DIST(x1,x2, y1, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
#define fast ios_base::sync_with_stdio(false);
template<typename T>inline string tostring(T a){ostringstream os("");os << a;return os.str();}
template<typename T>inline ll tolong(T a){ll res;istringstream os(a);os>>res;return res;}
template<typename T>inline vi parse(T str){vi res;int s;istringstream os(str);while(os>>s)res.pb(s);return res;}
template< class T > inline T _sqrt(T x) { return (T) sqrt( (double) x); }
template< class T > inline T _bigmod(T n,T m) {T ans=1,mult=n%mod; while(m){ if(m & 1) ans=(ans*mult)%mod; m>>=1; mult=(mult*mult)%mod; } ans%=mod; return ans;}
template< class T > inline T _modinv(T x) {return _bigmod(x,(T) mod-2)%mod;}
inline int len(string a) {return a.length();}
inline int len(char a[]) {return strlen(a);}
template<class T> inline T _gcd(T a, T b){return (b==0) ? a : _gcd(b, a % b);}
template< class T > inline T _lcm(T x,T y) { return x*y/_gcd(x,y);}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//bool compare(const pair<float,string>&i, const pair<float,string>&j)
//{
//    return i.first > j.first;
//}
//int in_c() { int c; for (; (c = getchar()) <= ' '; ) { if (!~c) throw ~0; } return c; }
//int EQ(double d) {
//    if ( fabs(d) < EPS ) return 0;
//    return d > EPS ? 1 : -1 ;
//}
const int me = 100025;

int N, Q;
int a[me], b[me], l[me], r[me];
int st[me << 3], lazy[me << 2];
vector<int> values;
void push(int I, int low, int high){
    if(lazy[I] != 0){
        st[I] += lazy[I];
        if(low != high){
            lazy[I << 1] += lazy[I];
            lazy[I << 1 | 1] += lazy[I];
        }
        lazy[I] = 0;
    }
}
void build(ll idx,ll l,ll r)
{
    if(l==r)
    {
        st[l]=values[l]-values[l-1];
        return;
    }
    build(idx<<1,l,(l+r)/2);
    build(idx<<1|1,(l+r)/2+1,r);
    st[idx]=st[idx<<1]+st[idx<<1|1];
}
void update(int I, int low, int high, int l, int r, int value){
    push(I, low, high);
    if(low > r || high < l)
        return;
    if(low >= l && high <= r){
        lazy[I] += value;
        push(I, low, high);
        return;
    }
    int mid = (low + high) >> 1;
    update(I << 1, low, mid, l, r, value);
    update(I << 1 | 1, mid + 1, high, l, r, value);
    st[I] = st[I << 1]+st[I << 1 | 1];
}
int get(int I, int low, int high, int l, int r){
    push(I, low, high);
    if(low > r || high < l)
        return 0;
    if(low >= l && high <= r)
        return st[I];
    int mid = (low + high) >> 1;
    return (get(I << 1, low, mid, l, r)+get(I << 1 | 1, mid + 1, high, l, r));
}
int main()
{
     clock_t begin = clock();
    //your code goes here
    cin >> N;
    cin >> Q;
    for(int i = 1; i <= Q; i ++)
        cin >> l[i] >> r[i]>>a[i];
    for(int i = 1; i <= Q; i ++)
    {
        values.push_back(l[i]);
        values.push_back(r[i]);
    }
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    for(int i = 1; i <= Q; i ++)
    {
        l[i] = (int)(lower_bound(values.begin(), values.end(), l[i]) - values.begin()) ;
        r[i] = (int)(lower_bound(values.begin(), values.end(), r[i]) - values.begin()) ;
    }
    int SZ = (int)values.size();
    build(1,0,SZ-1);
    cout<<get(1,0,SZ-1,0,SZ-1);
    for(int i = 1; i <= Q; i ++)
    {
        cout<<l[i]+1<<" "<<r[i]+1<<endl;
        if(a[i]==1)
        {
            update(1, 0, SZ-1, l[i], r[i], 0);
            cout << get(1, 0, SZ-1, 0, SZ-1) << endl;
        }
        else
        {
            update(1, 0, SZ-1, a[i], b[i], 1);
            cout << get(1, 0, SZ-1, 0, SZ-1) << endl;
        }
    }
   //end here
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    cerr<<"Running Time: "<<time_spent<<" Seconds"<<endl;
    return 0;
}



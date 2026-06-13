#ifdef __LOCAL
#define _GLIBCXX_DEBUG
#elifdef __GNUC__
#pragma GCC optimize("O3")
#endif
#include<bits/stdc++.h>
using namespace std;
using uint=unsigned int;
using ll=long long;
using ull=unsigned long long;
using i128=__int128;
using u128=unsigned __int128;
using ld=long double;
#define rep(i,n) for(ll i=0;i<(n);++i)
#define repr(i,n) for(ll i=(n)-1;i>=0;--i)
#define repa(i,a,b) for(ll i=(a);i<(b);++i)
#define repb(i,a,b) for(ll i=(b)-1;i>=(a);--i)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
struct ll2{
   ll a,b;
   friend auto operator<=>(const ll2&,const ll2&)=default;
};
struct ll3{
   ll a,b,c;
   friend auto operator<=>(const ll3&,const ll3&)=default;
};
struct ll4{
   ll a,b,c,d;
   friend auto operator<=>(const ll4&,const ll4&)=default;
};
struct ll5{
   ll a,b,c,d,e;
   friend auto operator<=>(const ll5&,const ll5&)=default;
};
struct ll6{
   ll a,b,c,d,e,f;
   friend auto operator<=>(const ll6&,const ll6&)=default;
};
struct frac{
   ll a,b;
   friend auto operator<=>(frac a,frac b){
      if(a.b==0&&b.b==0){
         if(a.a>0&&b.a>0)return 0;
         if(a.a<0&&b.a<0)return 0;
         if(a.a>0&&b.a<0)return -1;
         return 1;
      }
      if(a.b==0&&a.a>0)return -1;
      if(b.b==0&&b.a>0)return 1;
      if(a.b>=0&&b.b<=0)return -1;
      if(a.b<=0&&b.b>=0)return 1;
      if(a.a*b.b<a.b*b.a)return 1;
      if(a.a*b.b==a.b*b.a)return 0;
      return -1;
   }
};
constexpr ll MOD=998244353LL;
constexpr ll MOD2=1000000007LL;
constexpr ll IMOD=11451445450721LL;
constexpr ll B10=1024LL;
constexpr ll B20=1048576LL;
constexpr ll B30=1073741824LL;
constexpr ll B40=1099511627776LL;
constexpr ll B50=1125899906842624LL;
constexpr ll B60=1152921504606846976LL;
constexpr ll INF=B60;
constexpr ll E3=1000LL;
constexpr ll E6=1000000LL;
constexpr ll E9=1000000000LL;
constexpr ll E10=10000000000LL;
constexpr ll E12=1000000000000LL;
constexpr ll E15=1000000000000000LL;
constexpr ll E18=1000000000000000000LL;
constexpr ll2 D2[]={{0,1},{1,0}};
constexpr ll2 D4[]={{-1,0},{0,-1},{1,0},{0,1}};
constexpr ll2 D8[]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
constexpr char ALPH[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
constexpr char alph[]="abcdefghijklmnopqrstuvwxyz";
template<class T>
using pq=priority_queue<T,vector<T>,greater<>>;
template<class T>
using mset=multiset<T>;
template<class T,class U>
using mmap=multimap<T,U>;
template<class T>
using uset=unordered_set<T>;
template<class T,class U>
using umap=unordered_map<T,U>;
template<class T>
using vset=unordered_multiset<T>;
template<class T,class U>
using vmap=unordered_multimap<T,U>;
istream&operator>>(istream&is,i128&x){
   ll y;is>>y;x=y;
   return is;
}
ostream&operator<<(ostream&os,i128&x){
   os<<static_cast<ll>(x);
   return os;
}
ostream&operator<<(ostream&os,const ll2&o){
   os<<o.a<<' '<<o.b;
   return os;
}
ostream&operator<<(ostream&os,const ll3&o){
   os<<o.a<<' '<<o.b<<' '<<o.c;
   return os;
}
ostream&operator<<(ostream&os,const ll4&o){
   os<<o.a<<' '<<o.b<<' '<<o.c<<' '<<o.d;
   return os;
}
ostream&operator<<(ostream&os,const ll5&o){
   os<<o.a<<' '<<o.b<<' '<<o.c<<' '<<o.d<<' '<<o.e;
   return os;
}
ostream&operator<<(ostream&os,const ll6&o){
   os<<o.a<<' '<<o.b<<' '<<o.c<<' '<<o.d<<' '<<o.e<<' '<<o.f;
   return os;
}
// Print Vector
template<class T>
ostream&operator<<(ostream&os,const vector<T>&V){
   for(auto a:V)os<<a<<' ';
   return os;
}
// Print Set
template<class T>
ostream&operator<<(ostream&os,const set<T>&V){
   for(auto a:V)os<<a<<' ';
   return os;
}
// Print MultiSet
template<class T>
ostream&operator<<(ostream&os,const multiset<T>&V){
   for(auto a:V)os<<a<<' ';
   return os;
}
// Safe Division
ll dv(ll x,ll y){
   if(x>0)return x/y;
   return (x+((-x)/y+1)*y)/y-((-x)/y+1);
}
// Safe Mod
ll md(ll x,ll y){return x-y*dv(x,y);}
// Mod Power
ll mpow(ll x,ll y,ll mod=MOD){
   if(y==0)return 1%mod;
   ll t=mpow(x,y>>1,mod);
   if(y&1)return t*t%mod*x%mod;
   return t*t%mod;
}
// Extended GCD
ll2 egcd(ll a,ll b,ll t=1){
   if(a>b){
      auto[x,y]=egcd(b,a,t);
      return {x,y};
   }
   if(!a)return {0,t/b};
   auto[x,y]=egcd(b%a,a,t);
   return {y-b/a*x,x};
}
// Mod Inversion
ll minv(ll x,ll mod=MOD){return md(egcd(x,mod).a,mod);}
// Identity Matrix
vector<vector<ll>> imat(ll n,ll mod=MOD){
   vector X(n,vector<ll>(n,0));
   rep(i,n)X[i][i]=1%mod;
   return X;
}
// Matrix Prod
vector<vector<ll>> mtpr(vector<vector<ll>> X,vector<vector<ll>> Y,ll mod=MOD){
   vector Z(X.size(),vector<ll>(Y[0].size(),0));
   rep(i,X.size())rep(j,Y.size())rep(k,Y[0].size())Z[i][k]=(Z[i][k]+X[i][j]*Y[j][k])%mod;
   return Z;
}
// Matrix Power
vector<vector<ll>> mtpw(vector<vector<ll>> X,ll n,ll mod=MOD){
   if(!n)return imat(X.size(),mod);
   if(n%2)return mtpr(mtpw(X,n-1,mod),X,mod);
   auto Y=mtpw(X,n/2,mod);
   return mtpr(Y,Y,mod);
}
// Factorial
pair<vector<ll>,vector<ll>> fact(ll n,ll mod=MOD,bool inv=true){
   vector<ll> ans(n+1,1),ians(n+1);
   rep(i,n)ans[i+1]=ans[i]*(i+1)%mod;
   ians[n]=minv(ans[n],mod);
   repr(i,n)ians[i]=ians[i+1]*(i+1)%mod;
   return {ans,ians};
}
// Combination
ll comb(const vector<ll>&fct,const vector<ll>&ifct,ll n,ll r,ll mod=MOD){
   if(r<0||n<r||n<0)return 0;
   return fct[n]*ifct[r]%mod*ifct[n-r]%mod;
}
// Divisors
vector<ll> divs(ll n){
   vector<ll> ans;
   repa(i,1,static_cast<ll>(sqrt(static_cast<double>(n)))+1){
      if(n%i==0){
         ans.push_back(i);
         if(i!=n/i)ans.push_back(n/i);
      }
   }
   return ans;
}
// BFS
void bfs(const vector<vector<ll>>&G,vector<ll>&M,vector<ll> st){
   queue<ll> Q;
   for(ll s:st){
      Q.push(s);
      M[s]=0;
   }
   while(!Q.empty()){
      ll p=Q.front();Q.pop();
      for(ll q:G[p]){
         if(M[p]+1<M[q]){
            M[q]=M[p]+1;
            Q.push(q);
         }
      }
   }
}
// BFS with Parents
void bfsp(const vector<vector<ll>>&G,vector<ll>&M,vector<ll>&P,vector<ll> st){
   queue<ll> Q;
   for(ll s:st){
      Q.push(s);
      M[s]=0;
   }
   while(!Q.empty()){
      ll p=Q.front();Q.pop();
      for(ll q:G[p]){
         if(M[p]+1<M[q]){
            M[q]=M[p]+1;
            P[q]=p;
            Q.push(q);
         }
      }
   }
}
// 0-1BFS
void bfs1(const vector<vector<ll2>>&G,vector<ll>&M,vector<ll> st){
   deque<ll> Q;
   for(ll s:st){
      Q.push_back(s);
      M[s]=0;
   }
   while(!Q.empty()){
      ll p=Q.front();Q.pop_front();
      for(auto[d,q]:G[p]){
         if(M[p]+d<M[q]){
            M[q]=M[p]+d;
            if(d==1)Q.push_back(q);
            else Q.push_front(q);
         }
      }
   }
}
// Bellman-Ford
vector<ll> bf(ll n,const vector<ll3>&E,vector<ll> st){
   vector<ll> dis(n,INF);
   for(ll s:st)dis[s]=0;
   rep(i,n)for(auto[w,u,v]:E)if(dis[v]>dis[u]+w)dis[v]=dis[u]+w;
   for(auto[w,u,v]:E)if(dis[v]>dis[u]+w){
      rep(i,n)dis[i]=-INF;
      return dis;
   }
   return dis;
}
// Dijkstra
vector<ll> dij(const vector<vector<ll2>>&G,vector<ll> st){
   ll n=G.size();
   priority_queue<ll2,vector<ll2>,greater<>> Q;
   vector<ll> dis(n,INF);
   for(ll s:st){
      Q.emplace(0,s);
      dis[s]=0;
   }
   while(!Q.empty()){
      auto[d,p]=Q.top();Q.pop();
      if(d>dis[p])continue;
      for(auto[e,q]:G[p]){
         if(d+e<dis[q]){
            dis[q]=d+e;
            Q.emplace(d+e,q);
         }
      }
   }
   return dis;
}
// Warshall-Floyd
vector<vector<ll>> wf(const vector<vector<ll>>&G){
   ll n=G.size();
   vector dis(n,vector<ll>(n));
   rep(i,n){
      rep(j,n)dis[i][j]=G[i][j];
      dis[i][i]=0;
   }
   rep(k,n)rep(i,n)rep(j,n)dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
   return dis;
}
// Tree Diamiter
ll3 td(const vector<vector<ll>>&G){
   ll n=G.size();
   vector<ll> M1(n,INF);
   bfs(G,M1,{0});
   ll mx=-1,st;
   rep(i,n)if(M1[i]>mx){
      mx=M1[i];
      st=i;
   }
   vector<ll> M2(n,INF);
   bfs(G,M2,{st});
   mx=-1;ll gl;
   rep(i,n)if(M2[i]>mx){
      mx=M2[i];
      gl=i;
   }
   return {mx,st,gl};
}
// Union-Find
struct uf{
   vector<ll> par;
   explicit uf(ll n):par(n,-1){}
   ll find(ll u){
      vector<ll> A;
      while(par[u]>=0){
         A.push_back(u);
         u=par[u];
      }
      rep(i,A.size())par[A[i]]=u;
      return u;
   }
   bool same(ll u,ll v){return find(u)==find(v);}
   void merge(ll u,ll v){
      u=find(u);
      v=find(v);
      if(u==v)return;
      if(par[u]>par[v])swap(u,v);
      par[u]+=par[v];
      par[v]=u;
   }
};
// Weighted Union-Find
struct wuf{
   vector<ll> par;
   vector<ll> dif;
   explicit wuf(ll n):par(n,-1),dif(n){}
   ll2 find(ll u){
      vector<ll> A;
      ll dis=0;
      while(par[u]>=0){
         A.push_back(u);
         dis+=dif[u];
         u=par[u];
      }
      ll sum=dis;
      rep(i,A.size()){
         par[A[i]]=u;
         sum-=dif[A[i]];
         dif[A[i]]+=sum;
      }
      return {u,dis};
   }
   bool same(ll u,ll v){return find(u).a==find(v).a;}
   void merge(ll u,ll v,ll w){
      auto[ur,ud]=find(u);
      auto[vr,vd]=find(v);
      if(ur==vr)return;
      if(par[ur]>par[vr]){
         swap(ur,vr);
         w=-w;ud=-ud;vd=-vd;
      }
      par[ur]+=par[vr];
      par[vr]=ur;
      dif[vr]=w+ud-vd;
   }
   ll diff(ll u,ll v){return find(v).b-find(u).b;}
};
// Coordinate Compression
vector<ll> comp(const vector<ll>&A){
   ll n=A.size();
   set<ll> S;
   for(ll a:A)S.insert(a);
   vector<ll> T;
   for(ll s:S)T.push_back(s);
   vector<ll> ans(n);
   rep(i,n)ans[i]=distance(T.begin(),lower_bound(all(T),A[i]));
   return ans;
}
// MST
vector<ll3> mst(ll n,vector<ll3>&E){
   sort(all(E));
   uf U(n);
   vector<ll3> ans;
   for(auto[w,u,v]:E){
      if(!U.same(u,v)){
         U.merge(u,v);
         ans.emplace_back(w,u,v);
      }
   }
   return ans;
}
// Bipartite Coloring
vector<ll> bip(const vector<vector<ll>>&G){
   ll n=G.size();
   vector<ll> ans(n,-1);
   bool ok=true;
   rep(i,n){
      if(ans[i]==-1){
         ans[i]=0;
         queue<ll> Q({i});
         while(!Q.empty()){
            ll p=Q.front();Q.pop();
            for(ll q:G[p]){
               if(ans[q]==-1){
                  ans[q]=ans[p]^1;
                  Q.push(q);
               }else if(ans[q]==ans[p])ok=false;
            }
         }
      }
   }
   if(!ok)ans[0]=-1;
   return ans;
}
// Lowlink
pair<vector<ll>,vector<ll>> lowl(const vector<vector<ll>>&G,ll s){
   ll n=G.size();
   vector<ll> dis(n,-1),low(n);
   dis[s]=0;
   ll c=1;
   auto dfs=[&](auto&&dfs,ll x)->int{
      for(ll y:G[x]){
         if(dis[y]==-1){
            dis[y]=c;low[y]=c;++c;
            dfs(dfs,y);
            low[x]=min(low[x],low[y]);
         }else if(dis[y]<dis[x]-1)low[x]=min(low[x],dis[y]);
      }
      return 0;
   };
   dfs(dfs,s);
   return {dis,low};
}
// Map with Default Value
template<class S,class T>
struct dmap:map<S,T>{
   T def;
   explicit dmap(T def):def(def){}
   T&operator[](const S&i){return map<S,T>::emplace(i,def).first->second;}
};
int main(){
   cin.tie(0)->sync_with_stdio(0);
}

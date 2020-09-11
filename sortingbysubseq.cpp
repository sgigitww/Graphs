#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define ff first
#define ss second
#define rsz resize
#define ins insert 
#define mp make_pair
#define pf push_front 
#define pb push_back
#define eb emplace_back 
#define ft front() 
#define bk back()
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define deb(x) cout<<#x<<" "<<x<<'\n';
#define rep(i,a,b) for (int i = (a); i < (b); ++i)

const ll mod = 1e9+7; // 998244353;
const ll inf = 1e18; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<int> ans[100001],a(100001);
int b[100001];
int vis[100001],k,n;

bool comp(int p,int q){
	return a[p]<a[q];
}

void dfs(int u){
	vis[u]=1;
	ans[k].pb(u);
	
	if(!vis[b[u]]){
		dfs(b[u]);
	}
}

int main(){
    
    
    scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&a[i]);
		b[i]=i;
	}

	sort(b,b+n,comp);

	for(int i=0;i<n;++i){
		if(!vis[i]){
			dfs(i);
			k++;
		}
	}

	printf("%d\n",k);
	for(int i=0;i<k;++i){
		printf("%ld ",ans[i].size());
		for(auto x:ans[i]){
			printf("%d ",x+1);
		}printf("\n");
	}	

	return 0;

	/*STUFF TO LOOK:	
		1. Check the constraints
		2. Corner cases(n==0||n==1)
		3. Variables in loops
		4. Make sure two ints aren’t multiplied to get a long long
		5. Don't use scanf or printf while using ios_base
		6. using the local variable of the same name when global variable was required to be used
	*/
}

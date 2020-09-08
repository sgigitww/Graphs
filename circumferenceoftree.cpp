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
const ll inf = 1e9; 
const ld pie = acos((ld)-1);

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n;
vector<int> g[300001];
int vis[300001];
queue<int> q;
int dis[300001];

//make queue as q and distance as dis
template<typename T>
int bfs(T u){

	for(int i=0;i<n;++i){
		dis[i]=inf;
	}
	dis[u]=0;
	q.push(u);
	while(!q.empty()){

		T el = q.front();
		q.pop();
		for(auto x:g[el]){
			if(dis[x]==inf){
				q.push(x);
				dis[x]=dis[el]+1;
			}
		}
	}

	int ans=INT_MIN;
	int ind;
	for(int i=0;i<n;++i){
		if(ans<dis[i]){
			ans=dis[i];
			ind=i;
		}
	}

	return ind;
}

//make queue as q and distance as dis
template<typename T>
int bfs2(T u,T des){

	for(int i=0;i<n;++i){
		dis[i]=inf;
	}
	dis[u]=0;
	q.push(u);
	while(!q.empty()){

		T el = q.front();
		q.pop();
		for(auto x:g[el]){
			if(dis[x]==inf){
				q.push(x);
				dis[x]=dis[el]+1;
			}
		}
	}

	return dis[des];
}

int main(){
    
	
	scanf("%d",&n);
	if(n==1){
		int x;
		scanf("%d",&x);
		printf("0\n");
		return 0;
	}
	int temp;
	rep(i,0,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		temp=x;
		x--;
		y--;
		g[x].pb(y);
		g[y].pb(x);
	}


	int ans1 = bfs(temp);
	memset(dis,0,sizeof(dis));
	int ans2 = bfs(ans1);
	memset(dis,0,sizeof(dis));
	int ans = bfs2(ans1,ans2);

	printf("%d\n",3*ans);

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

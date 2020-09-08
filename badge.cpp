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



int main(){

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	rep(i,0,n) scanf("%d",&a[i]),a[i]--;
	int vis[n]={0};
	rep(i,0,n){

		int k = i;
		while(true){
			vis[k]=1;
			int p = a[k];
			if(vis[p]){
				printf("%d ",p+ 1);
				memset(vis,0,sizeof(vis));
				break;
			}
			k=p;
		}
	}printf("\n");


	return 0;

	/*STUFF TO LOOK:	
		1. Input ranges
		2. corner cases(n==0||n==1)
		3. Variables in loops
	*/
}

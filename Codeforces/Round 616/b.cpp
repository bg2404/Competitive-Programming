#include<bits/stdc++.h> 
 
#define mod 1000000007
#define mod2 998244353
#define int long long
#define endl "\n"
#define p_b push_back
#define m_p make_pair
#define pie pair<int,int>
using namespace std;
 
 
/* int swap */
 
void swap(int* a,int* b){
	int temp = *a;
	*a=*b;
	*b=temp;
}
 
char nxtchr(int c){
 
	if(c==1)return '1';
	if(c==2)return '2';
	if(c==3)return '3';
	if(c==4)return '4';
	if(c==5)return '5';
	if(c==6)return '6';
	if(c==7)return '7';
	if(c==8)return '8';
	if(c==9)return '9';
	if(c==0)return '0';
	return -1;
}
 
// int n,m,u,v;
// vector <int> adj[100005];
// bool vis[100005];
// void dfsUtil(int n){
 
// 	vis[n]=true;
 
// 	for(auto v: adj[n]){
 
// 		if(!vis[v])
// 			dfsUtil(v);
// 	}
// }
 
// int dfs(){
 
// 	int cnt=0;
// 	for(int i=1;i<=n;i++){
 
// 		if(!vis[i]){
// 			cnt++;
// 			dfsUtil(i);
// 		}
// 	}
// 	return cnt;
// }
 
/* gcd */
 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
 
int32_t main() {
	
	int t;
	cin>>t;
	while(t--){
 
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)cin>>a[i];
		
		if(n==1)cout<<"Yes"<<endl;
		else if(n==2&&!(a[0]==0&&a[1]==0))cout<<"Yes"<<endl;
		else if(n==2)cout<<"No"<<endl;
		else{
			int index=-1;
			for(int i=0;i<n;i++){
				if(a[i]>=i)continue;
				else{
					index=i;
					break;
				}
			}
			if(index==-1)cout<<"Yes"<<endl;
			else{
				bool yes=true;
				index--;	
				int val=a[index];
				for(int i=index+1;i<n;i++){
 
					if(a[i]>=val){
						a[i]=val-1;
					}	
					val=a[i];					
					if(a[i]<0){
						yes=false;
						break;
					}
				}
				if(!yes)cout<<"No"<<endl;
				else cout<<"Yes"<<endl;
			}
		}
	}
}
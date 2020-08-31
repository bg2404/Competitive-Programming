#include<bits/stdc++.h> 
 
#define mod 1000000007
#define mod2 998244353
#define int long long
#define endl "\n"
#define p_b insert
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
 
//  vis[n]=true;
 
//  for(auto v: adj[n]){
 
//      if(!vis[v])
//          dfsUtil(v);
//  }
// }
 
// int dfs(){
 
//  int cnt=0;
//  for(int i=1;i<=n;i++){
 
//      if(!vis[i]){
//          cnt++;
//          dfsUtil(i);
//      }
//  }
//  return cnt;
// }
 
/* gcd */
 
int gcd(int a, int b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
}
char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
 
const int V=26;
void DFSUtil(int v, bool visited[],set<int> adj[]) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    cout << alphabet[v]; 
  
    // Recur for all the vertices adjacent 
    // to this vertex 
    for (auto i:adj[v]) 
        if (!visited[i]) 
            DFSUtil(i, visited,adj); 
} 
  
// DFS traversal of the vertices reachable from v. 
// It uses recursive DFSUtil() 
void DFS(int v,set<int> adj[]) 
{ 
    // Mark all the vertices as not visited 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++) 
        visited[i] = false; 
  
    // Call the recursive helper function 
    // to print DFS traversal 
    DFSUtil(v, visited,adj); 
}
int32_t main() {
    
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        set<int> v[26];
        if(s.size()==1){
            cout<<"YES"<<endl;
            for(int i=0;i<26;i++)cout<<alphabet[i];
            cout << endl;
            continue;
        }

        for(int i=0;i<s.size()-1;i++){
            //cout<<s[i]<<"s"<<endl;
            v[s[i]-'a'].p_b(s[i+1]-'a');
            v[s[i+1]-'a'].p_b(s[i]-'a');
        }
        int one=0,two=0;
        bool yes=true;
        for(int i=0;i<26;i++){
            if(v[i].size()>=3){
                two++;
            }else if(v[i].size()==1){
                one++;
            }
        }
        if(one!=2||two>0)yes=false;
        if(!yes)cout<<"NO"<<endl;
        else{
            cout<<"YES"<<endl;
            int index;
            for(int i=0;i<26;i++){
                if(v[i].size()==0)cout<<alphabet[i];
                if(v[i].size()==1)index=i;
            }
            
            DFS(index,v);
            cout<<endl;
        }
    }
}
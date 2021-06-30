#include<bits/stdc++.h>

using namespace std;

char a[1000005], b[1000005];
int sa[1000005], sb[1000005];

int main() {
	scanf("%s%s", a+1, b+1);
	int n=strlen(a+1),m=strlen(b+1);
    for(int i=1;i<=n;i++)sa[i]=(a[i]-'0')^sa[i-1];
    for(int i=1;i<=m;i++)sb[i]=(b[i]-'0')^sb[i-1];
    int ans=0;
    for(int i=m;i<=n;i++)
    	if(!(sb[m]^sa[i]^sa[i-m]))++ans;
    cout<<ans<<endl;
	return 0;
}
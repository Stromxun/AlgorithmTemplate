#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <bitset>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long ll;
ll a[100010];
ll sum[100010];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
	{
     int n;
     scanf("%d",&n);
     
     for(int i=1;i<=n;i++)
     	{
     		scanf("%lld",&a[i]);
     		sum[i]=sum[i-1]+a[i];
     	}
	 ll ans=0;
	 for(ll i=1;i<=35;i++)//都要用long long
	 {
	 	ll l=1,r=0;
	 	ll minn=1ll<<(i-1),maxx=(1ll<<i)-1;
	 	if(i==1)
	 		 minn=0;
		for(ll x=1;x<=n;x++)
		{
			l=max(l,x);
			while(l<=n&&sum[l]-sum[x-1]<minn) l++;
			r=max(r,l-1); ///r=l-1是一个小技巧，可以判断他是否满足题目所给的条件
             while(r+1<=n&&sum[r+1]-sum[x-1]<=maxx&&sum[r+1]-sum[x-1]>=minn) r++;
			
			if(l>r) continue;
			ans=ans+(x*(r-l+1)+(r+l)*(r-l+1)/2)*i;
		}
	 }
	 printf("%lld\n", ans); 
	}
   
}
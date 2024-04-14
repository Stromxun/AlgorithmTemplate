#include<iostream>
#include<algorithm>
using namespace std;
const int maxa = 1e4 + 10;

int a[maxa];
int ans = 0;

int main()
{
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 2; i <= n - 1; i++){
        if(a[i] < a[i - 1] && a[i] < a[i + 1]){
            ans = max(ans, (a[i - 1] - a[i]) * (a[i + 1] - a[i]));
        }
    }
    cout << ans;
    return 0;
}

/*

        int[] v = new int[n+1];
        v[1] = 1;
        dfs(map,n,v,1L,1,map.get("1,1"));

        public static void dfs(HashMap<String,Integer> map,int n,int[] v,Long sum,int lastf,int lastBool){
        for(int i = 1;i <= n;i++){
            if(v[i]==0 && map.get("" +lastf + "," + i)  >= lastBool){
                v[i] = 1;
                if(sum+1 > ans)
                    ans = sum+1;
                dfs(map,n,v,sum+1,i,map.get(""+lastf +"," + i));
                v[i] = 0;
            }
        }
    }
*/
### HDU 4585 [Shaolin](https://acm.hdu.edu.cn/showproblem.php?pid=4585)
##### 知识点： Threap数、map 

<br>

map解法
```cpp
#include<iostream>
#include<map>

using namespace std;
map<int,int> mp;

int main(){
    int n;
    while(scanf("%d",&n),n){
        mp.clear();
        mp[1000000000]=1;  //方丈id = 1,等级 1000000000
        while(n--){        //此处方丈是作为哨兵的存在
            int id,g;
            scanf("%d %d",&id,&g); //新和尚 id ,等级 g
            mp[g]=id;          //新和尚进好队
            int ans;
            map<int,int>::iterator it=mp.find(g);//找到自身的位置
            if(it==mp.begin()){
                ans=(++it)->second;
            }else{
                map<int,int>::iterator it2=it;
                it2--;it++;
                if(g-it2->first<=it->first-g) //it指向的是战斗力比较小的和尚
                    ans=it2->second;          //it2指向的是战斗力较高的和尚
                else 
                    ans=it->second;
            }
            printf("%d %d\n",id,ans);
        }
    }
    return 0;
}
```

<br>

Thread(名次树)解法
```cpp

```

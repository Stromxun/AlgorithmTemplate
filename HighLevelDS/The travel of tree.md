### 已知两种序列遍历，求另外一种

##### 知前序、中序 求后序
```cpp
void afterford(string pre,string in){
    if (pre.size()>0){
        char ch=pre[0];
        int k=in.find(ch);
        afterford(pre.substr(1,k),in.substr(0,k));
        afterford(pre.substr(k+1),in.substr(k+1));//递归左右子树；
        cout<<ch;//找根输出
    }
}
```

##### 知中序、后序 求前序
```cpp
void beford(string in,string afte){
    if (in.size()>0){
        char ch=after[after.size()-1];
        cout<<ch;//找根输出
        int k=in.find(ch);
        beford(in.substr(0,k),after.substr(0,k));
        beford(in.substr(k+1),after.substr(k,in.size()-k-1));//递归左右子树；
    }
}
```

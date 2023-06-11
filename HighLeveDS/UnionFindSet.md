### 并查集
```cpp
    //needed 变量
    int fa[MAXSIZE];//存祖先编号
    
    //带权并查集 need
    int t[MAXSIZE]
```
###### 并查集初始化
```cpp
  for(int i=1;i<=n;i++){
      fa[i]=i;
      // 带权并查集 need
      t[i]= 0 or 1 //变量值看题意
  }
```

###### 朴素并查集
```cpp
  int find_father(int i){
      if(fa[i]==i) return i;
      else find(fa[i]);
  }
  
  void union(int x,int y){
      x=find_father(x);
      y=find_father(y);
      if(x!=y){
          fa[x]=y;
      }
  }
```

###### 路径压缩版并查集
```cpp
   int find_father(int i){
      if(fa[i]==i) return i;
      fa[i]=find(fa[i]);
      else fa[i];
  }
  
  void union(int x,int y){
      x=find_father(x);
      y=find_father(y);
      if(x!=y){
          fa[x]=y;
      }
  }
```

###### 带权并查集
```cpp
    int find_father(int i){
      if(fa[i]==i) return i;
      int temp=fa[i]
      fa[i]=find(fa[i]);
      t[i]+=t[temp];//追加权值
      else fa[i];
  }
  
  void union(int x,int y){
      x=find_father(x);
      y=find_father(y);
      if(x!=y){
          fa[x]=y;
          t[y]+=t[x];//继承权值
      }
  }
```

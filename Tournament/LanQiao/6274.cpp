#include<iostream>
using namespace std;
const int maxa = 1e5 + 10;
int a[maxa];

int main()
{
    int size = 0;
    bool cnt = true;
    for(int n = 1;; n++){
        cnt = true;
        for(int i = 1; i <= n && cnt; i++){
            for(int j = i; j <= i + 2 && cnt; j++){
                for(int k = i; k <= i + 2 && cnt; k++){
                    if(n == i * j * k){
                        size++;
                        if(size == 23){
                            cout << n;
                            return 0;
                        }
                        cnt = false;
                    }
                }
            }
        }
    }
    return 0;
}
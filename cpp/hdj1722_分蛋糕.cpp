//hdj1722, 125MS	368K	258 B	G++
//一次生日Party可能有p人或者q人参加,现准备有一个大蛋糕.
//问最少要将蛋糕切成多少块(每块大小不一定相等),才能使p人或者q人出席的任何一种情况,都能平均将蛋糕分食. 
//最少快数 n = p + q - gcd(p, q)
//不妨设蛋糕为矩形，从一条边平行地先划 p 条线， 将蛋糕等分成 p 份，然后还从这条边平行地划 q 条线，将蛋糕
//等分成 q 份， 这样就既可以满足 p 个人，又可以满足 q 个人，两次划线可能有重合，重合的次数为gcd(p,q)
#include<iostream>
using namespace std;
int gcd(int x,int y){
    if(x==y) return x;
    else if(x>y) return gcd(x-y,y);
    else return gcd(y-x,x);
}
int main(){
    int p,q;
    while(cin>>p>>q)
        cout<<p+q-gcd(p,q)<<endl;
    return 0;
}
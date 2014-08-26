//Simpson公式求积分，31MS	336K	1026 B	G++
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int a, b;

//函数，即y=f(x)
double F(double x){
    return sqrt((1-x*x/a/a)*b*b);
}


//三点simpson法
double simpson(double a,double b){
    double c=a+(b-a)/2;
    return (F(a)+4*F(c)+F(b))/6 * (b-a);
}


//自适应simpson公式（递归过程）。一直整个区间[a,b]上的三点simpson值A
double asr(double a,double b,double eps,double A){
    double c=a+(b-a)/2;
    double L=simpson(a,c); //将原图分成两部分，分别计算各部分的面积
    double R=simpson(c,b);
    if(fabs(L+R-A)<=15*eps){    //与在原图上直接应用一次Simpson公式相比较
        return L+R+(L+R-A)/15;
    }
    return asr(a,c,eps,L)+asr(c,b,eps,R);
}


//自适应simpson公式（主过程）
double asr(double a,double b,double eps){
    return asr(a,b,eps,simpson(a,b));
}

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d%d%d%d",&a,&b,&l,&r);
        printf("%.3lf\n",asr(l,r,1e-6)*2);
    }
}

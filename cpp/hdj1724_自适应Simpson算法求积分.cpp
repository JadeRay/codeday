//Simpson��ʽ����֣�31MS	336K	1026 B	G++
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int a, b;

//��������y=f(x)
double F(double x){
    return sqrt((1-x*x/a/a)*b*b);
}


//����simpson��
double simpson(double a,double b){
    double c=a+(b-a)/2;
    return (F(a)+4*F(c)+F(b))/6 * (b-a);
}


//����Ӧsimpson��ʽ���ݹ���̣���һֱ��������[a,b]�ϵ�����simpsonֵA
double asr(double a,double b,double eps,double A){
    double c=a+(b-a)/2;
    double L=simpson(a,c); //��ԭͼ�ֳ������֣��ֱ��������ֵ����
    double R=simpson(c,b);
    if(fabs(L+R-A)<=15*eps){    //����ԭͼ��ֱ��Ӧ��һ��Simpson��ʽ��Ƚ�
        return L+R+(L+R-A)/15;
    }
    return asr(a,c,eps,L)+asr(c,b,eps,R);
}


//����Ӧsimpson��ʽ�������̣�
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

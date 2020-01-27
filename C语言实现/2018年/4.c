#include <stdio.h>
#include <math.h>

double cubeRoot(double x);

int main()
{
    printf("%lf", cubeRoot(-8));
    return 0;
}

/***牛顿迭代法
    f(x[n]) + f'(x[n])(x - x[n]) = 0
->  f(x[n]) + f'(x[n])(x[n+1] - x[n]) = 0
->  x[n+1] = x[n] - f(x[n])/f'(x[n])
***/

double cubeRoot(double x)                   //牛顿迭代法  f(x[n]) + f'(x[n])(x - x[n]) = 0
{                                           //          ->f(x[n]) + f'(x[n])(x[n+1] - x[n]) = 0
    double yn=1,yp=x;
    double epsilon = 0.00001;
    while(1)
    {
        yn=yp-(yp*yp*yp-x)/(3*yp*yp);
        if(fabs(yp-yn)<epsilon)
            break;
        yp=yn;
    }
    return yn;
}

//double cubeRoot(double x)                       //二分法最关键的就是确定初始区间的范围
//{
//    int flag = 1;
//    double high, low, mid, i = 0.00001;
//    if(x < 0)                                   //小于零，取相反数
//    {
//        flag = 0;
//        x = -x;
//    }
//    high = x, low = 0;
//    if(x < 1)                                   //如果小于1的话x^3-k=0的解肯定在0-1
//        high = 1;                               //否则在0-k
//    while(1)
//    {
//        mid = low + (high - low) / 2;
//        if(fabs(mid * mid * mid - x) < i)       //满足精度退出
//            break;
//        if( (mid * mid * mid - x) * (low * low * low - x) < 0 )
//            high = mid;
//        else
//            low = mid;
//    }
//
//    if(flag)
//        return mid;
//    else
//        return -mid;
//}

//double cubeRoot(double x)
//{
//    double lwbd=0,upbd=x,mid;
//    double epsilon=1e-5;
//    if(x<1)
//        upbd=1; // root is in the range [lwbd,upbd]
//    while(upbd-lwbd>epsilon)
//    {
//        mid=lwbd+(upbd-lwbd)/2;
//        if(mid*mid*mid-x<0)
//            lwbd=mid;
//        else
//            upbd=mid;
//    }
//    return mid;
//}

//double cubeRoot(double x)
//{
//    return exp(log(x) / 3);
//}

//double cubeRoot(double x)
//{
//    return pow(x, (double)1 / (double)3);
//}

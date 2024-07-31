/*Напиши С++ програм кој користи inline функција circleArea која бара влез од корисникот за радиус на круг, ја пресметува и ја печати површината на
 * кругот.*/
#include <iostream>

using std::cin;
using std::cout;

inline double circleArea(double radius){
    return radius * radius * 3.14;
}

int main()
{
    double radius;
    cout<<"Vnesi radius na krug:";
    cin>>radius;
    cout<<"Povrsinata na krugot e "<<circleArea(radius);
    return 0;
}

/*Табелирај ја вредноста на i, i2,  и за вредности на i=1,2,... n. Ведностите да бидат прикажани во колони со ширина m (за децималните вредности да
 * се дефинира соодветна прецизност). Вредностите на n и m треба да се внесат на почетокот на програмата.*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int m, n;
    cout<<"Vnesi n:";
    cin>>n;
    cout<<"Vnesi m:";
    cin>>m;
    cout<<left<<setw(m)<<"i"<<setw(m)<<"i^2"<<setw(m)<<"sqrt(i)"<<"cbrt(i)"<<endl;
    cout.precision(2);
    for(int i = 1; i <= n; i++){
        cout<<left<<setw(m)<<i<<setw(m)<<i * i<<setw(m)<<sqrt(i)<<cbrt(i)<<endl;
    }

    return 0;
}

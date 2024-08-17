/*Во примерот
template<typename R, typename P>

R implicit_cast(const P& p) {
  return p;
}

int main() {
  int i = 1;

  float x = implicit_cast<float>(i);

  int j = implicit_cast<int>(x);
} //kraj na main
замени ги R и P. Дали кодот се компајлира? Во што се состои проблемот? */
#include <iostream>

using namespace std;

template<typename P, typename R>

R implicit_cast(const P& p) {
    return p;
}

int main() {
    int i = 1;

    float x = implicit_cast<float>(i);

    int j = implicit_cast<int>(x);
}
/*Кодот не се компајлира бидејќи првиот параметар е типот што треба да се врати(P) а враќа R.*/

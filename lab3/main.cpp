#include "figure.h"

using namespace std;

#include <iostream>

int main()
{
    //MultiplyMatrix();
    circle c1;
    c1.create_figure();
    cout<<c1;
    c1.move_figure(1,2);
    cout<<c1;
    c1.rotate_figure(3.14);
    cout<<c1;
    c1.create_figure();
    c1.move_n_rotate(1,2,3.14);
    cout<<c1;
    return 0;
}

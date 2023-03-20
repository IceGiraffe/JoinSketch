// #include "xis/gen_scheme.h"
#include "xis/xis.h"
#include "xis/xis.cpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

void place(int &a, int &b)
{
    if (a > b)
    {
        auto tmp = a;
        a = b;
        b = tmp;
    }
    return;
}

int main()
{
    srand(time(NULL));
    while (true)
    {
        int a = rand() % 0x00ffffff;
        int b = rand() % 0x00ffffff;
        place(a, b);
        auto sum = 0;
        Xi_BCH3 xi(0x12345678, 0x23456789);
        for (int i = a; i <= b; i++)
        {
            // sum += xi.element(i);
            cout << xi.element(i) << " ";
        }
        auto interval = xi.interval_sum(a, b);
        cout << a << " " << b << " " << sum << " " << interval << endl;
        assert(sum == interval);
    }
}
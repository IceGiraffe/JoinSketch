#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <vector>
#include <fstream>
#include <numeric>
#include <iomanip>
#include "include/Sketch.h"
#include "include/JoinSketch_ver3.h"

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
    // while (true)
    // {
    //     int a = rand() % 0x00ffffff;
    //     int b = rand() % 0x00ffffff;
    //     place(a, b);
    //     auto sum = 0;
    //     Xi_BCH3 xi(0x12345678, 0x23456789);
    //     for (int i = a; i <= b; i++)
    //     {
    //         // sum += xi.element(i);
    //         cout << xi.element(i) << " ";
    //     }
    //     auto interval = xi.interval_sum(a, b);
    //     cout << a << " " << b << " " << sum << " " << interval << endl;
    //     assert(sum == interval);
    // }
    Short_C_Sketch sketch1(60, 3);
    for (int i = 100; i < 210; i++){
        sketch1.Insert(i);
    }
    sketch1.print();
    Short_C_Sketch sketch2(60, 3);
    sketch2.InsertRange(100, 209);


    sketch2.print();
}
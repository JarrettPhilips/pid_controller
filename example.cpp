#include "pid.h"

#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;

#include <iostream>

int main(){
    plt::plot({1,3,2,4});
    plt::show();
    return 0;
}

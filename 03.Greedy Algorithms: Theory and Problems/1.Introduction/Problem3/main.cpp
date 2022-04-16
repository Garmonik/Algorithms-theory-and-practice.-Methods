#include<iostream>
#include<cmath>
#include<cassert>

int main(){
    unsigned long int total;
    std::cin >> total;
    assert(total > 0);

    unsigned long int n = ceil((sqrt(8*total + 9) - 5) / 2);
    unsigned long int last = total - n * (n + 1) / 2;

    std::cout << n + 1 << std::endl;
    for(unsigned long int i = 1; i <= n; i++){
        std::cout << i << " ";
    }
    std::cout << last << std::endl;
    return 0;
}

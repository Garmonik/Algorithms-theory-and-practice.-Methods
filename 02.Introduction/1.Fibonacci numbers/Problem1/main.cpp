#include<iostream>
#include<vector>

int main(){
    int n;

    std::cin >> n;

    std::vector <int> arr(40);
    arr[0]=0;
    arr[1]=1;

    for (int i=2; i<41; i++){
        arr[i] = arr[i-1]+arr[i-2];
    }

    std::cout << arr[n];
    return 0;
}

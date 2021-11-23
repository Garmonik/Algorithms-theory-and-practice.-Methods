#include<iostream>

int fibonacci(int n);

int main(void){
	int n;

	std::cin >> n;;
	std::cout << fibonacci(n) << std::endl;
    
    return 0;
}

int fibonacci(int n){
	int neg1 = 1,
	    neg2 = 0,
	    temp = 0,
	    num = 0;

	switch(n){
	case 1:
		return 1;
		break;
	default:
		for(int i = 1; i < n; i++){
			temp = (neg1 + neg2) % 10;
			neg2 = neg1;
			neg1 = temp;
		}
		break;
	}
	return temp;
}

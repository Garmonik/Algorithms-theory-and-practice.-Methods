#include<iostream>
#include<map>

int main(){
    int count;
    std::string str_in;
    std::string simbol;
    std::string code;
    std::map <std::string, char> table;
    std::cin >> count >> str_in;
    for(int i = 0; i < count; i++){
        std::cin >> simbol >> code;
        table[code] = simbol[0];
    }
    std::cin >> str_in;
    while(str_in.length() > 0){
        for(auto i: table){
            if(str_in.compare(0, i.first.length(), i.first) == 0){
                std::cout << i.second;
                str_in = str_in.substr(i.first.length(), str_in.length());
            }
        }
    }
    return 0;
}

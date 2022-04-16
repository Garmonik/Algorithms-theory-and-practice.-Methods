#include<cassert>
#include<cstdint>
#include<iostream>
#include<vector>
#include<algorithm>

struct Item final{
    int weight;
    int value;

    bool operator<(const Item& rhs) const noexcept{
        return (static_cast<double>(weight) / value) < (static_cast<double>(rhs.weight) / rhs.value);
    }
};

double get_max_knapsack_value(int capacity, std::vector <Item> items){
    double value = 0.0;
    std::sort(std::begin(items), std::end(items));

    for(auto&& item : items){
        if(capacity > item.weight){
            capacity -= item.weight;
            value += item.value;
        }
        else{
            value += item.value * (static_cast<double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}

int main(void){
    int number_of_items;
    int knapsack_capacity;
    std::cin >> number_of_items >> knapsack_capacity;
    std::vector <Item> items(number_of_items);
    for(auto&& item : items){
        std::cin >> item.value >> item.weight;
    }

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << max_knapsack_value << std::endl;
    return 0;
}

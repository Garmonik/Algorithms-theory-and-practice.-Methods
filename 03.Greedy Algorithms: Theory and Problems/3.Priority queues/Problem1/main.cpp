#include<iostream>
#include<cstring>

template <typename T>
class priority_queue
{
public:
    priority_queue(){
        _size = 10;

        _data = new T[_size];
        memset(_data, 0x00, _size * sizeof(T));

        _count = 0;
    }

    ~priority_queue(){
        delete[] _data;
    }

    void push(T value){
        _count += 1;

        if(_count == _size)
            resize();

        _data[_count - 1] = value;
        sift_up(_count - 1);
    }

    T extract_max()
    {
        if(_count == 0)
            return T();

        T max_value = _data[0];

        _data[0] = _data[_count - 1];
        _count -= 1;

        if(_count != 0)
            sift_down(0);

        return max_value;
    }

private:
    T *_data;
    size_t _size;
    size_t _count;

    void resize(){
        size_t new_size = _size + 30;

        T *new_data = new T[new_size];
        memset(new_data, 0x00, new_size * sizeof(T));
        memcpy(new_data, _data, _size * sizeof(T));

        delete[] _data;

        _size = new_size;
        _data = new_data;
    }

    void sift_up(size_t index){
        if(index == 0)
            return;

        size_t parent = index / 2;

        if(_data[index] < _data[parent])
            return;

        std::swap(_data[index], _data[parent]);
        sift_up(parent);
    }

    void sift_down(size_t index){
        size_t left = 2 * index;
        size_t right = 2 * index + 1;

        if(left > _count - 1)
            return;

        if(right > _count - 1){
            if(_data[index] > _data[left])
                return;

            std::swap(_data[index], _data[left]);
        }
        else{
            if(_data[index] >= _data[left] && _data[index] >= _data[right])
                return;

            size_t temp = (_data[left] > _data[right]) ? left : right;
            std::swap(_data[index], _data[temp]);
            sift_down(temp);
        }
    }
};

int main(void){
    priority_queue<long long int> queue;

    int command_count = 0;
    std::cin >> command_count;
    std::cin.ignore();

    //считываем словарь

    for(int i = 0; i < command_count; ++i){
        std::string command;
        std::cin >> command;

        if(std::strcmp(command.data(), "Insert") == 0){
            long long int value = 0;
            std::cin >> value;

            queue.push(value);
        }

        if(std::strcmp(command.data(), "ExtractMax") == 0){
            std::cout << queue.extract_max() << std::endl;
        }
    }

    return 0;
}

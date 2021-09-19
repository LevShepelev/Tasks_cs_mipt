#include <list>
#include <map>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <ctime>
#include <iterator>
using namespace std;

const int IN_CODE   = 1;
const int OUT_CODE  = 2;
const int MAIN_CODE = 3;

template<typename T, typename KeyT = int>
class Cache
    {
    struct Node_d {T data; char list_code = 0; int page_numb;}; //Node with real data
    using ListIt = typename std::list<Node_d>::iterator;
    
    public:
        Cache(int in_size, int out_size, int main_size);
        void Searching(int page_number);
        long hit_counter_ = 0;
        
        
    private:
        unordered_map<KeyT, ListIt> hash_;

        list<Node_d> input_; 
        list<Node_d> output_;
        list<Node_d> main_list_;
        long  in_max_size_  = 0;
        long out_max_size_  = 0;
        long main_max_size_ = 0;
        int input_last_key  = 0;
        

        void Push_to_input(int page_number);
        void Push_to_output(Node_d elem);
        void Push_to_main_list(int page_number);
        T get_data(int page_number);

    };


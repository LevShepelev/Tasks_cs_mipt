#include "cache.h"


template <typename T, typename KeyT>
Cache<T, KeyT>::Cache(ifstream& input_stream)
    {
    in_max_size_ = size / 4;
    out_max_size_ = size / 2;
    main_max_size_ = size / 4;
    istream_ = input_stream;
    itream_ >> size_;
    input_ = list<T>;
    output_ = list<T>;
    main_list_ = list<T>; 
    cout << input_.front() << endl;
    }


template <typename T, typename KeyT>
void Cache<T, KeyT>::Searching()
    {
    int page_number;
    istream_ >> number_of_pages_;
    for (int i = 0; i < number_of_pages_; i++)
        {
        istream >> page_number;
        if (hash_.count(page_number) == 0 && input_.size() < in_max_size_)
            {
            input_.push_front(get_data())
            hash_[page_number] = hash_.begin();
            }
        else if (hash_.count(page_number) == 0 && input_.size() == in_max_size_)
            {
            
            input_.pop_back()
            }
        }
    }


void Cache<T, KeyT>::input_push()


int main()
    {
    ifstream input("data.txt");
    Cache<char> cache(input);

    }
#include "cache.h"


template <typename T, typename KeyT>
Cache<T, KeyT>::Cache(int in_size, int out_size, int main_size)
    {
    in_max_size_ = in_size;
    out_max_size_ = out_size;
    main_max_size_ = main_size;
    }


template <typename T, typename KeyT>
void Cache<T, KeyT>::Searching(int page_number)
    {
    printf("page_number = %d\n", page_number);
    if (hash_.count(page_number) == 0)  //New page
        Push_to_input(page_number);
    else 
        {
        if ((*hash_[page_number]).list_code == IN_CODE) //page in Input
            {
            input_.erase(hash_[page_number]);
            if (page_number = 1238)
                {
                printf("1238\n");
                getchar(); 
                }
            input_.push_front(*(hash_[page_number]));
            }
        else if ((*hash_[page_number]).list_code == OUT_CODE) //page in Output
            {
            Push_to_main_list(page_number);
            output_.erase(hash_[page_number]);                                                                     
            }
        else if ((*hash_[page_number]).list_code == MAIN_CODE) //page in Main_list
            {
            main_list_.splice(hash_[page_number], main_list_, main_list_.begin());
            }
        hit_counter_++;     
        }
    printf("page_numb_true = %d, pointer = %p data = %c page_numb = %d\n", page_number, hash_[page_number], (*hash_[page_number]).data, (*hash_[page_number]).page_numb);
    }

template <typename T, typename KeyT>
void Cache<T, KeyT>::Push_to_input(int page_number)
    {
    printf("Push in Input\n");
    if (in_max_size_ == input_.size())
        {
        input_.back().list_code = OUT_CODE;
        Push_to_output(input_.back());
        input_.pop_back();
        }
    input_.push_front({get_data(page_number), IN_CODE, page_number});
    hash_[page_number] = input_.begin();
    }


template <typename T, typename KeyT>
void Cache<T, KeyT>::Push_to_output(Node_d elem)
    {
    printf("Push_in_Output\n");
    if (output_.size() == out_max_size_) 
        {
        hash_.erase(output_.back().page_numb);
        output_.pop_back();
        output_.push_front(elem);
        }
    output_.push_front(elem);
    }


template <typename T, typename KeyT>
void Cache<T, KeyT>::Push_to_main_list(int page_number)
    {
    printf("Push in main\n");
    (*hash_[page_number]).list_code = MAIN_CODE;
    if (main_list_.size() == main_max_size_) 
        {
        hash_.erase(main_list_.back().page_numb);
        main_list_.pop_back();
        main_list_.push_front(*hash_[page_number]);
        }
    main_list_.push_front(*hash_[page_number]);
    }


template <typename T, typename KeyT>
T Cache<T, KeyT>::get_data(int page_number)
    {
    return 48;
    }


int main()
    {
    clock_t start, end;
    start = clock();
    int total_memory = 0, numb_of_pages = 0, page_number = 0;
    ifstream input("./Tests/004.dat");
    input >> total_memory >> numb_of_pages;
        Cache<char> cache((total_memory + 3) / 4, total_memory / 2, (total_memory + 1) / 4);
    for (int i = 0; i < numb_of_pages; i++)
        {
        input >> page_number;
        if (i == 6699)
            getchar();
        //printf("i = %d\n", i);
        cache.Searching(page_number);
        }
    end = clock();
    printf("Well done, Hits = %ld, hit_procent = %f, time = %f\n", cache.hit_counter_, (float) cache.hit_counter_ / numb_of_pages * 100, (float) (end - start) / (CLOCKS_PER_SEC));
    }
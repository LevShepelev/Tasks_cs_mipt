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
    Print_curren_state_of_lists();
    //printf("page_number = %d\n", page_number);
    if (hash_.count(page_number) == 0)  //New page
        Push_to_input(page_number);
    else 
        {
        if ((*hash_[page_number]).list_code == IN_CODE) //page in Input
            {
            Node_d buf = *(hash_[page_number]);
            //printf("%p, %c", hash_[page_number], *(hash_[page_number]));
            input_.erase(hash_[page_number]);
            input_.push_front(buf);
            hash_[page_number] = input_.begin();
            }
        else if ((*hash_[page_number]).list_code == OUT_CODE) //page in Output
            {
            if (main_max_size_ > 0)
                Push_to_main_list(page_number);
            else printf("main_size = 0\n");
            }
        else if ((*hash_[page_number]).list_code == MAIN_CODE) //page in Main_list
            {
            Node_d buf = *(hash_[page_number]);
            main_list_.erase(hash_[page_number]);
            main_list_.push_front(buf);
            hash_[page_number] = main_list_.begin();
            }
        hit_counter_++;     
        }
    //printf("page_numb_true = %d, pointer = %p data = %c page_numb = %d\n", page_number, hash_[page_number], (*hash_[page_number]).data, (*hash_[page_number]).page_numb);
    }

template <typename T, typename KeyT>
void Cache<T, KeyT>::Push_to_input(int page_number)
    {
    //printf("Push in Input\n");
    if (in_max_size_ == input_.size())
        {
        Push_to_output(input_.back().page_numb);
        input_.pop_back();
        }
    input_.push_front({get_data(page_number), IN_CODE, page_number});
    hash_[page_number] = input_.begin();
    }


template <typename T, typename KeyT>
void Cache<T, KeyT>::Push_to_output(int page_number)
    {
    (*hash_[page_number]).list_code = OUT_CODE;
    //printf("Push_in_Output\n");
    if (output_.size() == out_max_size_) 
        {
        assert(hash_.erase(output_.back().page_numb) == 1);
        output_.pop_back();
        }
    output_.push_front(*(hash_[page_number]));
    hash_[page_number] = output_.begin();
    }


template <typename T, typename KeyT>
void Cache<T, KeyT>::Push_to_main_list(int page_number)
    {
    printf("Push in main\n");
    (*hash_[page_number]).list_code = MAIN_CODE;
    if (main_list_.size() == main_max_size_) 
        {
        printf("main pop\n");
        assert(hash_.erase(main_list_.back().page_numb) == 1);
        main_list_.pop_back();
        }
    printf("%d(%d)\n", (hash_[page_number]) -> page_numb, (hash_[page_number]) -> list_code);
    main_list_.push_front(*(hash_[page_number]));
    
    hash_[page_number] = main_list_.begin();
    output_.erase(hash_[page_number]);
    Print_curren_state_of_lists();
    }


template <typename T, typename KeyT>
void Cache<T, KeyT>::Print_curren_state_of_lists()
    {
    printf("In input, size = %ld\n", input_.size());
    for (auto item : input_)
        printf("%d(%d) ", item.page_numb, item.list_code);

    printf("\nIn output, size = %ld\n", output_.size());
    for (auto item : output_)
        printf("%d(%d) ", item.page_numb, item.list_code); 

    printf("\nIn main, size = %ld\n", main_list_.size());
    for (auto item : main_list_)
        printf("%d(%d) ", item.page_numb, item.list_code); 
    putchar('\n');
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
    ifstream input("./Tests/003.dat");
    input >> total_memory >> numb_of_pages;
        Cache<char> cache((total_memory + 3) / 4, total_memory / 2, (total_memory + 1) / 4);
    printf("sizes : input %d output %d main %d\n", (total_memory + 3) / 4, total_memory / 2, (total_memory + 1) / 4);
    for (int i = 0; i < numb_of_pages; i++)
        {
        input >> page_number;
        //printf("i = %d\n", i);
        cache.Searching(page_number);
        }
    end = clock();
    printf("Well done, Hits = %ld, hit_procent = %f, time = %f\n", cache.hit_counter_, (float) cache.hit_counter_ / numb_of_pages * 100, (float) (end - start) / (CLOCKS_PER_SEC));
    }
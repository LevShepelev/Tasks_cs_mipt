#include "Ideal_cache.h"

int main(int argc, char** argv)
    {
    clock_t start, end;
    start = clock();
    int total_memory = 0, numb_of_pages = 0, page_number = 0;
    ifstream input(argv[1]);
    if (!input.is_open())
        {
        cout << "File doesnt exist" << endl;
        return 1;
        }
    input >> total_memory >> numb_of_pages;
    int requests[numb_of_pages];
    Ideal_cache<char> cache(total_memory);

    for (int i = 0; i < numb_of_pages; i++)
        {
        input >> page_number;
        requests[i] = page_number;
        cache.Reading_pages(page_number, i);
        }
    for (int i = 0; i < numb_of_pages; i++)
        {
        cache.Searching(requests[i], i);
        }
    end = clock();
    printf("%11s, Hits = %7d, hit_procent = %5f, time = %10f\n", argv[1], cache.hit_counter_, (float) cache.hit_counter_ / numb_of_pages * 100, (float) (end - start) / (CLOCKS_PER_SEC));
    }
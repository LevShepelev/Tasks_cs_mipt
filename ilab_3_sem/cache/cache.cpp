#include "cache.h"

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
    Cache<char> cache((total_memory + 3) / 4, total_memory / 2, (total_memory + 1) / 4);
    for (int i = 0; i < numb_of_pages; i++)
        {
        input >> page_number;
        cache.Searching(page_number);
        }
    end = clock();
    printf("%11s, Hits = %7ld, hit_procent = %5f, time = %10f\n", argv[1], cache.hit_counter_, (float) cache.hit_counter_ / numb_of_pages * 100, (float) (end - start) / (CLOCKS_PER_SEC));
    }
#include <cstdio>

class vector 
        {
        public:
        int a_;
        int b_;
        vector(int x, int y) {a_ = x; b_ = y;};
        vector operator + (vector x);
        };



vector vector::operator + (vector x)
    {
    vector res (0, 0);
    res.a_ = a_ + x.a_;
    res.b_ = b_ + x.b_;
    return res;
    }



int main()
    {
    vector v1 (2, 4);
    vector v2 (3, 5);
    v1 = v1 + v2;
    printf("a = %d b = %d", v1.a_, v1.b_);
    }
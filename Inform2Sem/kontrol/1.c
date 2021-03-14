#include <stdio.h>
struct Point {
    int x;
    int y;
};
struct Rect {
    struct Point lt; // left top
    struct Point rb; // right bottom
};
void transform (struct Rect * r) 
    {
    int x1 = (r -> lt).x;
    int y1 = (r -> lt).y;
    int x2 = (r -> rb).x;
    int y2 = (r -> rb).y;
    (r -> lt).x = x2;
    (r -> lt).y = y2;
    (r -> rb).x = 2*x2 -x1;
    (r -> rb).y = 2*y2 - y1;
    }
int main()
{
    struct Rect rect = {{-1, 1}, {4, -2}};
    printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
    transform(&rect);
    printf("%d %d %d %d\n", rect.lt.x, rect.lt.y, rect.rb.x, rect.rb.y);
    return 0;
}

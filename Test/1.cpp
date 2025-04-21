#define sum(a, b) a + b

#undef sum
#define sum(a, b) a *b
#include <iostream>
int main()
{
    sum(5, 6);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#if defined(__x86_64__)
#include "x86_64.s"
#elif defined(__arm__)
#include "arm.s"
#elif defined(__mips__)
#include "mips.s"
#else
#error "Unsupported architecture"
#endif

typedef struct
{
    void *stack;
    void *stack_pointer;
    void *base_pointer;
} Context;

void save_context(Context *context)
{
    asm volatile("save_context" : "=r"(context->stack_pointer), "=r"(context->base_pointer));
}

void restore_context(Context *context)
{
    asm volatile("restore_context" : : "r"(context->stack_pointer), "r"(context->base_pointer));
}

void func1(int x)
{
    while (x < 1000)
    {
        if (x == 6)
            sleep(1000);
    }
}

int main()
{
    Context c1, c2;
    void *s1 = malloc(8192);
    void *s2 = malloc(8192);
    c1.stack = s1;
    c2.stack = s2;
    int x = 1;
    save_context(&c1);
    x++;
    restore_context(&c1);
    printf("%d", x);
    return 0;
}
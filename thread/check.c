#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Forward declarations for assembly functions
extern void save_context(void* context);
extern void restore_context(void* context);

typedef struct
{
    // Context buffer to store CPU state
    // Size should be enough for all registers
    char context_data[256];
} Context;

int main()
{
    Context c1;
    int x = 1;
    
    printf("Before save_context: x = %d\n", x);
    
    // Save current context
    static int restored = 0;
    if (!restored) {
        save_context(&c1);
        restored = 1;
        x++;
        printf("After increment: x = %d\n", x);

        if (x < 5) {
            // Only restore a few times to avoid infinite loop
            restore_context(&c1);
        }
    }

    printf("Final: x = %d\n", x);
    return 0;
}
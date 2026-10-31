#include <stdio.h>

int main(void)
{
    int c;
    int count = 0;
    while ((c = getchar()) != '#'){
        if ((c == 'a') || (c == '@'))
            count++;
    }
    printf("%d\n", count);
    return 0;
}

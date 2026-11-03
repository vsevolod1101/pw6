#include <stdio.h>
#define CURRENCY "USD"
#define C1 1.0
#define C2 0.8
#define C3 0.5
#define MAX 1000

int main(void)
{
    int input;
    if ((scanf("%d", &input) != 1) || input <= 0 || input > MAX) return 1;
    if (input < 10)
        printf("%.2f %s\n", C1*input, CURRENCY);
    else if (input < 60)
        printf("%.2f %s\n", C2*input, CURRENCY);
    else 
        printf("%.2f %s\n", C3*input, CURRENCY);
    return 0;
}

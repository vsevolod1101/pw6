#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, tens, units, tens_mt_units_c = 0, tens_lt_units_c = 0, tens_mt_units_s = 0, tens_lt_units_s = 0;
    scanf("%d", &i);
    while(i != 0) {
        i = abs(i);
        tens = ((i / 10) % 10);
        units = (i % 10);
        if (tens > units) {
            tens_mt_units_c++;
            tens_mt_units_s += i;
        } else if (tens < units) {
            tens_lt_units_c++;
            tens_lt_units_s += i;
        }
        scanf("%d", &i);
    }
    printf("Tens more than units count: %d\n", tens_mt_units_c);
    printf("Average of it: %.3f\n\n", tens_mt_units_c != 0 ? (double)tens_mt_units_s / (double)tens_mt_units_c : 0.0f);

    printf("Tens less than units count: %d\n", tens_lt_units_c);
    printf("Average of it: %.3f\n", tens_lt_units_c != 0 ? (double)tens_lt_units_s / (double)tens_lt_units_c : 0.0f);
    return 0;
}

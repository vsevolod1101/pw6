#include <stdio.h>
#include <string.h>

void flushstdin(void);
int dec_to_bin(int d, int arr[]);
int get_uint(int *input_uint);
int get_hex(unsigned int *input_hex);

int main(void)
{
    int input_uint;
    unsigned int input_hex;
    int arr[40];
    int on = 1;
    int rc;
    while(on)
    {
        printf(
            "Choose option:\n"
            "1) dec→hex\n"
            "2) dec→oct\n"
            "3) dec→bin\n"
            "4) hex→dec\n"
            "5) выход\n"
        );
        if ((rc = get_uint(&input_uint)) == -1) break;
        else if (rc == 0) continue;
        switch (input_uint)
        {
        case 1:
            printf("dec: ");
            if ((rc = get_uint(&input_uint)) == -1) {
                on = 0;
                break;
            } else if (rc == 0) break;
            printf("dec→hex %d→%x\n", input_uint, input_uint);
            break;
        case 2:
            printf("dec: ");
            if ((rc = get_uint(&input_uint)) == -1) {
                on = 0;
                break;
            } else if (rc == 0) break;
            printf("dec→oct %d→%o\n", input_uint, input_uint);
            break;
        case 3:
            printf("dec: ");
            if ((rc = get_uint(&input_uint)) == -1) {
                on = 0;
                break;
            } else if (rc == 0) break;
            printf("dec→bin %d→", input_uint);
            if (input_uint == 0)
                printf("0");
            else for (int i = dec_to_bin(input_uint, arr) - 1; i >= 0; i--) printf("%d", arr[i]);
            putchar('\n');
            break;
        case 4:
            printf("hex: ");
            if ((rc = get_hex(&input_hex)) == -1) {
                on = 0;
                break;
            } else if (rc == 0) break;
            printf("hex→dec %x→%u\n", input_hex, input_hex);
            break;
        case 5:
            on = 0;
            break;
        default:
            printf("\nError: incorrect option\n\n");
            break;
        }
    }
    return 0;
}

int dec_to_bin(int d, int arr[]) 
{
    int i = 0;
    while (d != 0) {
        arr[i] = d % 2;
        d /= 2;
        i++;
    }
    return i;
}

int get_uint(int *input_uint)
{
    char uint_buf[11];
    if (!fgets(uint_buf, sizeof(uint_buf), stdin)) {
        return -1;
    } else if (sscanf(uint_buf, "%9d", input_uint) != 1 || *input_uint < 0) {
        printf("\nError: incorrect input\n\n");
        return 0;
    }
    if (!strchr(uint_buf, '\n')) flushstdin();
    return 1;
}

int get_hex(unsigned int *input_hex)
{
    char hex_buf[10];
    if (!fgets(hex_buf, sizeof(hex_buf), stdin)) {
        return -1;
    } else if (sscanf(hex_buf, "%8x", input_hex) != 1) {
        printf("\nError: incorrect input\n\n");
        return 0;
    }
    if (!strchr(hex_buf, '\n')) flushstdin();
    return 1;
}

void flushstdin(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

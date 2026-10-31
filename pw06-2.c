#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main(void)
{
    setlocale(LC_ALL, "");
    wint_t last = WEOF;
    wint_t cur;
    int count = 0;
    while((cur = getwchar()) != L'#'){
        if (last == L'е' && cur == L'й')
            count++;
        last = cur;
    }
    printf("%d\n", count);
    return 0;
}

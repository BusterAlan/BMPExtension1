#include <stdio.h>

int main() {

    FILE* f;
    f = fopen("C:\\bmps\\bitmap.bmp", "rb");
    if (f == NULL) { printf("No se ha encontrado el archivo"); }
    char buf[1000];
    fread(buf, 1, 2, f);

    printf("%c", buf[0]);
    printf("%c", buf[1]);

}


#include <stdio.h>
#include <stdint.h>
#include <malloc.h>

int main() {

    #pragma pack(1)
    typedef struct {

        uint16_t type;
        uint32_t size;
        uint16_t reserved1;
        uint16_t reserved2;
        uint32_t offset;
        uint32_t dib_header_size;
        uint32_t width_px;
        uint32_t height_px;
        uint16_t num_planes;
        uint16_t bits_per_pixel;
        uint32_t compression;
        uint32_t image_size_bytes;
        uint32_t x_resolution_ppm;
        uint32_t y_resolution_ppm;
        uint32_t num_colors;
        uint32_t important_colors;

    } BMPHeader;

    typedef struct {

        uint8_t r;
        uint8_t g;
        uint8_t b;

    } pixelColor;

    typedef struct {

        BMPHeader header;
        unsigned char* data;

    } BMPImage;

    #pragma pack()

    FILE* f;

    char route[100] = "C:\\bmps\\one.bmp";

    f = fopen(route, "rb");
    
    if (f == NULL) printf("No se ha encontrado el archivo\n");

    char buf[1000];

    BMPImage bmp;
    fread(&bmp, sizeof(BMPHeader), 1, f);

    uint8_t pixel[3];
    fread(pixel, sizeof(uint8_t), 3, f);

    printf("#%02X%02X%02X\n", pixel[2], pixel[1], pixel[0]);

    fclose(f);
    return 0;

}



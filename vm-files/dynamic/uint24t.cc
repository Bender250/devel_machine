// clang++ -std=c++11 uint24t.cc -fsanitize=address
#include <cstdint>

typedef struct _bytes3_t{
        uint8_t data[3];
} bytes3_t;

typedef struct _bitword24_t{
  uint32_t data: 24;
} bitword24_t;

void enc_48(uint8_t *in) {
    bytes3_t *three_byte_ptr = (bytes3_t *)in;
    uint32_t y_word = (*(bitword24_t *)three_byte_ptr).data;
    uint32_t x_word = (*(bitword24_t *)(three_byte_ptr + 1)).data;
    
    // feistel network...
}

int main(void) {
    uint8_t data[6] = {0};

    enc_48(data);
}

#include "stdio.h"
#include "stdlib.h"
#include "pico/stdlib.h"

#define DEVICE_NAME "my-pico-device"
#define DEVICE_VRSN "v0.0.1"
const uint LED_PIN = 25;

int main()
{
    stdio_init_all();
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    char symbol = getchar();
    printf("received char: %c [ ASCII code: %d ]\n", symbol, symbol);
    while (1){
        char symbol = getchar();
        switch(symbol)
        {
        case 'e':
            gpio_put(LED_PIN, true);
            printf("led enable done\n");
            break;
        default:
            break;
        }
        switch(symbol)
        {
        case 'd':
            gpio_put(LED_PIN, false);
            printf("led disable done\n");
            break;
        default:
            break;
        }
        switch(symbol)
        {
        case 'v':
            printf("Device name: '%s'\n", DEVICE_NAME);
            printf("Device version: '%s'\n", DEVICE_VRSN);
            break;
        default:
            break;
        }
    }
}
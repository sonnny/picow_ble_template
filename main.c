#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "blink.h"

static int led_on = true;
struct bt_type data;

void main(void){
  stdio_init_all();
  sleep_ms(1000);
  gpio_init(15);
  gpio_set_dir(15,GPIO_OUT);
  multicore_launch_core1(bt_main);
  sleep_ms(1000);
  for(;;){
    sleep_ms(40);
    bt_get_latest(&data);
    if (data.data == 0x74) gpio_put(15,1); // 't'
    if (data.data == 0x75) gpio_put(15,0); // 'u'
  }
}

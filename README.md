# picow_ble_template

demo ble on pico w
attach an led on gpio15
blink.h define your data structure
blink.h add bt_get_latest(struct bt_type *dst); to get latest data

main call bt_get_latest after sleep

git clone
mkdir build
cd build
cmake ..
make
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program demo.elf verify reset exit"

idea from https://github.com/usedbytes/picow_ds4


demo ble on pico w
attach an led on gpio15
I'm using picoprobe to upload using picoprobe

in main.c do your work in for(;;) loop
send 't' from your ble device to turn on led on gpio15
send 'u' from your ble device to turn off led on gpio15

git clone https://github.com/sonnny/picow_ble_template
cd picow_ble_template
edit CMakeLists.txt to your own sdk path
mkdir build
cd build
cmake ..
make
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program demo.elf verify reset exit"

to use on your own project
clone this repository
edit CMakeLists.txt to your own sdk path
edit blink.h bt_type to your own struct
in main.c declare your own bt_type struct
in blink.c function nordic_spp_packet_handler,
    check case RFCOMM_DATA_PACKET:
        is receiving and being copied in your bt_type latest struct
        bt_type latest is declare in blink.c
        
after editing to your needs
compile (see above)

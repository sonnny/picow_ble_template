
demo ble on pico w<br>
attach an led on gpio15<br>
I'm using picoprobe to upload using picoprobe<br>
<br>
in main.c do your work in for(;;) loop<br>
send 't' from your ble device to turn on led on gpio15<br>
send 'u' from your ble device to turn off led on gpio15<br>

git clone https://github.com/sonnny/picow_ble_template<br>
cd picow_ble_template<br>
edit CMakeLists.txt to your own sdk path<br>
mkdir build<br>
cd build<br>
cmake ..<br>
make<br>
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program demo.elf verify reset exit"
<br>
<br>
to use on your own project<br>
clone this repository<br>
edit CMakeLists.txt to your own sdk path<br>
edit blink.h bt_type to your own struct<br>
in main.c declare your own bt_type struct<br>
<br>
<ul>
    <li>in blink.c function nordic_spp_packet_handler</li>
    <li>check case RFCOMM_DATA_PACKET:</li>
    <li>is receiving and being copied in your bt_type latest struct</li>
    <li>bt_type latest is declare in blink.c</li>
</ul>
<br>    
after editing to your needs<br>
compile (see above)<br>

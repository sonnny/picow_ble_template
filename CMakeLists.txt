
cmake_minimum_required(VERSION 3.12)
set(PICO_SDK_PATH "/home/sonny/pico/pico-sdk")
set(PICO_SDK_POST_LIST_DIRS "/home/sonny/pico/pico-extras")
set(PICO_BOARD "pico_w")
include("${PICO_SDK_PATH}/external/pico_sdk_import.cmake")
include("${PICO_SDK_POST_LIST_DIRS}/external/pico_extras_import.cmake")
project(blink_v1 C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(blink_v1
    main.c
    blink.c
	)
target_link_libraries(blink_v1
    pico_stdlib
    hardware_gpio
    pico_btstack_ble
    pico_btstack_cyw43
    pico_btstack_classic
    pico_cyw43_arch_none
    pico_multicore
    )
pico_enable_stdio_usb(blink_v1 0)
pico_enable_stdio_uart(blink_v1 1)
target_include_directories(blink_v1 PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}
    )
pico_btstack_make_gatt_header(blink_v1 PRIVATE "${CMAKE_CURRENT_LIST_DIR}/mygatt.gatt")
pico_add_extra_outputs(blink_v1)

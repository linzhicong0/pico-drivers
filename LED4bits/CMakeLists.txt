cmake_minimum_required(VERSION 3.12)

# Set the pico sdk path
# set(PICO_SDK_PATH /Users/linzhicong/pico/pico-sdk)

include(pico_sdk_import.cmake)

project(LED4bits C CXX ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(led4bits main.c include/led.h led.c)

pico_add_extra_outputs(led4bits)

target_link_libraries(led4bits pico_stdlib)

pico_enable_stdio_usb(led4bits 1)
pico_enable_stdio_uart(led4bits 0)

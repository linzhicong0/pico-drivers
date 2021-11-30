cmake_minimum_required(VERSION 3.12)

# Set the pico sdk path
# set(PICO_SDK_PATH /Users/linzhicong/pico/pico-sdk)

include(pico_sdk_import.cmake)

project(LCD C CXX ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(lcd1602 main.c include/lcd1602.h lcd1602.c include/lcd1602_cmd.h)

pico_add_extra_outputs(lcd1602)

target_link_libraries(lcd1602 pico_stdlib)

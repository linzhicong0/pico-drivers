cmake_minimum_required(VERSION 3.12)

# Set the pico sdk path
# set(PICO_SDK_PATH /Users/linzhicong/pico/pico-sdk)

include(pico_sdk_import.cmake)

project(led C CXX ASM)

set(CMAKE_C_STANDARD 11)

set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(led led.c include/flash_led.h flash_led.c)

pico_add_extra_outputs(led)

target_link_libraries(led pico_stdlib)

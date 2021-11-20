# pico-drivers
这个仓库是用pico来驱动不同硬件

This repository is using pico to drive different hardwares

# description
使用前请必须先按照pico官方文档进行SDK的安装和配置

Please install the official sdk before compiling the code

# how to
## 如何使用
1. 在对应的驱动文件夹中创建build文件夹
2. 在build文件夹中运行 cmake ..
3. 运行 make， 即可生成对应的.uf2文件到build目录下
4. 将生成的.uf2拖到pico中即可运行

## how to compile and run
1. Create a build folder inside the driver you want to build
2. Go inside the build folder you created and run cmake..
3. Run make, it will create .uf2 file inside the build folder
4. Drag the .uf2 file to pico

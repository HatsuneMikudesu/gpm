
# Path to root dir
SDK_DIR_MK = $(dir $(realpath $(lastword ${MAKEFILE_LIST})))
SDK_DIR_CUR = $(CURRENT_DIR)
SDK_ROOTDIR := ${SDK_DIR_MK}

# Absolute path to makefiles
MAKEFILES_ROOTDIR := ${SDK_ROOTDIR}/boards/bsp/make

CONFIG_FILE := ${SDK_ROOTDIR}/src/app/app_config.mk
include ${CONFIG_FILE}


# TC_PATH_INST_ARMCC := C:\Keil_v5\ARM\ARMCC
# TC_PATH_INST_ARMCLANG := C:\Keil_v5\ARM\ARMCLANG
# TC_PATH_INST_GCC:= D:\envir\gcc-arm-none-eabi
# TC_OPENOCD_PATH := D:\envir\openocd\xpack-openocd-0.11.0-1

TC_PATH_INST_ARMCC := D:\__dev_envir\__env\mdk5\CORE\ARM\ARMCC
TC_PATH_INST_ARMCLANG := D:\__dev_envir\__env\mdk5\CORE\ARM\ARMCLANG
TC_PATH_INST_GCC:= D:\__dev_envir\__env\arm_gcc\gcc-arm-none-eabi
TC_OPENOCD_PATH := D:\__dev_envir\__env\openocd\xpack-openocd-0.11.0-1

# including common build makefile
include $(MAKEFILES_ROOTDIR)/common/build.mk

all: prebuild build postbuild

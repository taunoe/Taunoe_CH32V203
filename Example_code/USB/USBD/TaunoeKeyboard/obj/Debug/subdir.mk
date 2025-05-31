################################################################################
# MRS Version: 2.1.0
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/SRC/Debug/debug.c 

C_DEPS += \
./Debug/debug.d 

OBJS += \
./Debug/debug.o 



# Each subdirectory must supply rules for building sources it contributes
Debug/debug.o: /home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/SRC/Debug/debug.c
	@	riscv-none-embed-gcc -march=rv32imacxw -mabi=ilp32 -msmall-data-limit=8 -msave-restore -fmax-errors=20 -Os -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections -fno-common -Wunused -Wuninitialized -g -I"/home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/SRC/Debug" -I"/home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/SRC/Core" -I"/home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/USB/USBD/TaunoeKeyboard/User" -I"/home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/SRC/Peripheral/inc" -I"/home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/USB/USBD/TaunoeKeyboard/User/USBLIB/CONFIG" -I"/home/taunoerik/Documents/MyGitHub/Taunoe_CH32V203/Example_code/USB/USBD/TaunoeKeyboard/User/USBLIB/USB-Driver/inc" -std=gnu99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"


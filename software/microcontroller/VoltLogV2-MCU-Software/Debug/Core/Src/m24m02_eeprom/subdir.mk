################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/m24m02_eeprom/m24m02_eeprom.c 

OBJS += \
./Core/Src/m24m02_eeprom/m24m02_eeprom.o 

C_DEPS += \
./Core/Src/m24m02_eeprom/m24m02_eeprom.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/m24m02_eeprom/%.o Core/Src/m24m02_eeprom/%.su Core/Src/m24m02_eeprom/%.cyclo: ../Core/Src/m24m02_eeprom/%.c Core/Src/m24m02_eeprom/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-m24m02_eeprom

clean-Core-2f-Src-2f-m24m02_eeprom:
	-$(RM) ./Core/Src/m24m02_eeprom/m24m02_eeprom.cyclo ./Core/Src/m24m02_eeprom/m24m02_eeprom.d ./Core/Src/m24m02_eeprom/m24m02_eeprom.o ./Core/Src/m24m02_eeprom/m24m02_eeprom.su

.PHONY: clean-Core-2f-Src-2f-m24m02_eeprom


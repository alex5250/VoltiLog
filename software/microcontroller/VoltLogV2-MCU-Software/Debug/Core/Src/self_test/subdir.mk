################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/self_test/self_test_i2c.c 

OBJS += \
./Core/Src/self_test/self_test_i2c.o 

C_DEPS += \
./Core/Src/self_test/self_test_i2c.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/self_test/%.o Core/Src/self_test/%.su Core/Src/self_test/%.cyclo: ../Core/Src/self_test/%.c Core/Src/self_test/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I../FATFS/Target -I../FATFS/App -I../USB_DEVICE/App -I../USB_DEVICE/Target -I../Middlewares/Third_Party/FatFs/src -I../Middlewares/ST/STM32_USB_Device_Library/Core/Inc -I../Middlewares/ST/STM32_USB_Device_Library/Class/MSC/Inc -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM3 -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src-2f-self_test

clean-Core-2f-Src-2f-self_test:
	-$(RM) ./Core/Src/self_test/self_test_i2c.cyclo ./Core/Src/self_test/self_test_i2c.d ./Core/Src/self_test/self_test_i2c.o ./Core/Src/self_test/self_test_i2c.su

.PHONY: clean-Core-2f-Src-2f-self_test


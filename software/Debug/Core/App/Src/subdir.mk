################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/App/Src/uartApp.c \
../Core/App/Src/uartTransport.c 

OBJS += \
./Core/App/Src/uartApp.o \
./Core/App/Src/uartTransport.o 

C_DEPS += \
./Core/App/Src/uartApp.d \
./Core/App/Src/uartTransport.d 


# Each subdirectory must supply rules for building sources it contributes
Core/App/Src/%.o Core/App/Src/%.su: ../Core/App/Src/%.c Core/App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Core/App/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-App-2f-Src

clean-Core-2f-App-2f-Src:
	-$(RM) ./Core/App/Src/uartApp.d ./Core/App/Src/uartApp.o ./Core/App/Src/uartApp.su ./Core/App/Src/uartTransport.d ./Core/App/Src/uartTransport.o ./Core/App/Src/uartTransport.su

.PHONY: clean-Core-2f-App-2f-Src


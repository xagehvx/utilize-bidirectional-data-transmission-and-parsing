################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
C:/STM/include/startup_stm32g031k8tx.s 

C_SRCS += \
../I2C.c \
../bsp.c \
../eeprom.c \
../main.c \
../mpu6050.c \
C:/STM/include/system_stm32g0xx.c 

OBJS += \
./I2C.o \
./bsp.o \
./eeprom.o \
./main.o \
./mpu6050.o \
./startup_stm32g031k8tx.o \
./system_stm32g0xx.o 

S_DEPS += \
./startup_stm32g031k8tx.d 

C_DEPS += \
./I2C.d \
./bsp.d \
./eeprom.d \
./main.d \
./mpu6050.d \
./system_stm32g0xx.d 


# Each subdirectory must supply rules for building sources it contributes
I2C.o: ../I2C.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"I2C.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
bsp.o: ../bsp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"bsp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
eeprom.o: ../eeprom.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"eeprom.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
main.o: ../main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
mpu6050.o: ../mpu6050.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"mpu6050.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
startup_stm32g031k8tx.o: C:/STM/include/startup_stm32g031k8tx.s
	arm-none-eabi-gcc -mcpu=cortex-m0plus -g -c -x assembler-with-cpp -MMD -MP -MF"startup_stm32g031k8tx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"
system_stm32g0xx.o: C:/STM/include/system_stm32g0xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g -DSTM32 -DSTM32G031xx -DSTM32G0 -DNUCLEO_G031K8 -DSTM32G031K8Tx -DDEBUG -c -I../../include -O0 -ffunction-sections -fdata-sections -Wall -Wextra -pedantic -Wmissing-include-dirs -Wconversion -fstack-usage -MMD -MP -MF"system_stm32g0xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"


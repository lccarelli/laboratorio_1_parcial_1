################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Parcial_1.c \
../src/electro.c \
../src/marca.c \
../src/reparacion.c \
../src/servicio.c \
../src/utn.c 

OBJS += \
./src/Parcial_1.o \
./src/electro.o \
./src/marca.o \
./src/reparacion.o \
./src/servicio.o \
./src/utn.o 

C_DEPS += \
./src/Parcial_1.d \
./src/electro.d \
./src/marca.d \
./src/reparacion.d \
./src/servicio.d \
./src/utn.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



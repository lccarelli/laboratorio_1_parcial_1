################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Parcial_1.c \
../src/cliente.c \
../src/electro.c \
../src/informes.c \
../src/marca.c \
../src/reparacion.c \
../src/servicio.c \
../src/utn.c 

OBJS += \
./src/Parcial_1.o \
./src/cliente.o \
./src/electro.o \
./src/informes.o \
./src/marca.o \
./src/reparacion.o \
./src/servicio.o \
./src/utn.o 

C_DEPS += \
./src/Parcial_1.d \
./src/cliente.d \
./src/electro.d \
./src/informes.d \
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



################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FunesMemory9.c \
../contexto.c \
../paginacion_invertida.c \
../segmentacion_paginada.c \
../segmentacion_pura.c \
../utilidades_fm9.c \
../utilidades_para_listas.c 

OBJS += \
./FunesMemory9.o \
./contexto.o \
./paginacion_invertida.o \
./segmentacion_paginada.o \
./segmentacion_pura.o \
./utilidades_fm9.o \
./utilidades_para_listas.o 

C_DEPS += \
./FunesMemory9.d \
./contexto.d \
./paginacion_invertida.d \
./segmentacion_paginada.d \
./segmentacion_pura.d \
./utilidades_fm9.d \
./utilidades_para_listas.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -Ireadline -Ilqvg -Icommons -Ipthread -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



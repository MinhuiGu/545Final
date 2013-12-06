################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Connector/EClientSocketBase.cpp \
../Connector/EPosixClientSocket.cpp 

OBJS += \
./Connector/EClientSocketBase.o \
./Connector/EPosixClientSocket.o 

CPP_DEPS += \
./Connector/EClientSocketBase.d \
./Connector/EPosixClientSocket.d 


# Each subdirectory must supply rules for building sources it contributes
Connector/%.o: ../Connector/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/minhuigu/Downloads/curl-7.33.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



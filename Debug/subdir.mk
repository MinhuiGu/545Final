################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Buy_Sell.cpp \
../DateAscPrint.cpp \
../DateDescRewrite.cpp \
../Download.cpp \
../Logger.cpp \
../Main.cpp \
../MetaData.cpp \
../Pairs.cpp \
../PosixTestClient.cpp \
../Prettyprint_Decorator.cpp \
../Signal_Iterator.cpp \
../Stock_Base.cpp \
../Stock_Factory.cpp 

OBJS += \
./Buy_Sell.o \
./DateAscPrint.o \
./DateDescRewrite.o \
./Download.o \
./Logger.o \
./Main.o \
./MetaData.o \
./Pairs.o \
./PosixTestClient.o \
./Prettyprint_Decorator.o \
./Signal_Iterator.o \
./Stock_Base.o \
./Stock_Factory.o 

CPP_DEPS += \
./Buy_Sell.d \
./DateAscPrint.d \
./DateDescRewrite.d \
./Download.d \
./Logger.d \
./Main.d \
./MetaData.d \
./Pairs.d \
./PosixTestClient.d \
./Prettyprint_Decorator.d \
./Signal_Iterator.d \
./Stock_Base.d \
./Stock_Factory.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/Users/minhuigu/Downloads/curl-7.33.0/include -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



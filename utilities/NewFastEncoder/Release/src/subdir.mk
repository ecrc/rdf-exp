################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/FastEncoder.cpp \
../src/TurtleParser.cpp \
../src/partitioner_store.cpp \
../src/profiler.cpp \
../src/utils.cpp 

OBJS += \
./src/FastEncoder.o \
./src/TurtleParser.o \
./src/partitioner_store.o \
./src/profiler.o \
./src/utils.o 

CPP_DEPS += \
./src/FastEncoder.d \
./src/TurtleParser.d \
./src/partitioner_store.d \
./src/profiler.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/home/harbir/sparsehash/include -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



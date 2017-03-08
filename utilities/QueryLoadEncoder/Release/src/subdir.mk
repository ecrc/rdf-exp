################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/QueryLoadEncoder.cpp \
../src/SPARQLLexer.cpp \
../src/SPARQLParser.cpp \
../src/node.cpp \
../src/profiler.cpp \
../src/query.cpp \
../src/utils.cpp 

OBJS += \
./src/QueryLoadEncoder.o \
./src/SPARQLLexer.o \
./src/SPARQLParser.o \
./src/node.o \
./src/profiler.o \
./src/query.o \
./src/utils.o 

CPP_DEPS += \
./src/QueryLoadEncoder.d \
./src/SPARQLLexer.d \
./src/SPARQLParser.d \
./src/node.d \
./src/profiler.d \
./src/query.d \
./src/utils.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '



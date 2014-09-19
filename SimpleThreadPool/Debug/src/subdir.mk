################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
O_SRCS += \
../src/Test.o \
../src/ThreadPoolTest.o 

CPP_SRCS += \
../src/Test.cpp \
../src/ThreadPoolTest.cpp \
../src/Thread_Pool.cpp 

OBJS += \
./src/Test.o \
./src/ThreadPoolTest.o \
./src/Thread_Pool.o 

CPP_DEPS += \
./src/Test.d \
./src/ThreadPoolTest.d \
./src/Thread_Pool.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '



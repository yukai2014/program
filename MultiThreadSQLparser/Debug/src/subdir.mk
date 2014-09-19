################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/function.cpp \
../src/sql.tab.cpp \
../src/testyu2.cpp 

C_SRCS += \
../src/lex.yy.c 

OBJS += \
./src/function.o \
./src/lex.yy.o \
./src/sql.tab.o \
./src/testyu2.o 

C_DEPS += \
./src/lex.yy.d 

CPP_DEPS += \
./src/function.d \
./src/sql.tab.d \
./src/testyu2.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GCC C++ Compiler'
	g++ -O0 -g3 -w -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo '正在构建文件： $<'
	@echo '正在调用： GCC C Compiler'
	g++ -O0 -g3 -w -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '



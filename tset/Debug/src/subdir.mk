################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/false\ sharing.cpp \
../src/select.cpp \
../src/testsf.cpp \
../src/tset.cpp 

OBJS += \
./src/false\ sharing.o \
./src/select.o \
./src/testsf.o \
./src/tset.o 

CPP_DEPS += \
./src/false\ sharing.d \
./src/select.d \
./src/testsf.d \
./src/tset.d 


# Each subdirectory must supply rules for building sources it contributes
src/false\ sharing.o: ../src/false\ sharing.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I/home/imdb/supports/boost_1_53_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/false sharing.d" -MT"src/false\ sharing.d" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '

src/%.o: ../src/%.cpp
	@echo '正在构建文件： $<'
	@echo '正在调用： GNU C++ 编译器'
	g++ -I/home/imdb/supports/boost_1_53_0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo '已结束构建： $<'
	@echo ' '



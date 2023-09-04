

cc=g++
# 手动指定 默认最终目标
.DEFAULT_GOAL = main

# makefile 的第一个目标会被默认设置为最终目标而进行执行

main : main.o
	g++ main.o -o main

main.o : main.cpp
	g++ -c main.cpp

ifeq ($(OS),Windows_NT)
# MAIN	:= main.exe
# SOURCEDIRS	:= $(SRC)
# INCLUDEDIRS	:= $(INCLUDE)
# LIBDIRS		:= $(LIB)
# FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
# MD	:= mkdir
else
# MAIN	:= main
# SOURCEDIRS	:= $(shell find $(SRC) -type d)
# INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
# LIBDIRS		:= $(shell find $(LIB) -type d)
# FIXPATH = $1
RM = rm -f
# MD	:= mkdir -p
endif


# 伪目标 声明 .PHONY: 目标 ，防止存在相同名称的文件

.PHONY: clean

# 伪目标
clean:
	-$(RM) main.o
	-$(RM) main.exe
	@echo Clean complete!

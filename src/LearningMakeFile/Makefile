CC=g++
# 手动指定 默认最终目标
.DEFAULT_GOAL = hello.o

# makefile 的第一个目标会被默认设置为最终目标而进行执行

hello: hello.o
	g++ hello.o -o hello


hello.o: hello.cpp ; g++ -c hello.cpp




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
	-$(RM) hello.o
	-$(RM) hello.exe
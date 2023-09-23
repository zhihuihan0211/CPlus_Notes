CC=g++

# .DEFAULT_GOAL = main



main: main.o
	g++ main.o -o main

main.o: main.cpp ; g++ -c main.cpp




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
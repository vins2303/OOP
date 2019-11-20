CC = g++ -g
encoding = -fexec-charset=UTF-8
main = main.cpp
out = -o main.exe
lib_map = lib/Map
lib_LifeEntity = lib/LifeEntity
# SRC = $(wildcard *.c) $(wildcard inc/*.c)
lib = $(wildcard $(lib_map)/*.cpp) $(wildcard $(lib_LifeEntity)/*.cpp)
ALL:
	$(CC) $(encoding) $(main) $(lib) $(out)
files_c := $(wildcard src/**/*.c) $(wildcard Testing/**/**/*.c) $(wildcard Testing/**/*.c) $(wildcard TestingMultiCore/**/*.c) $(wildcard TestingMultiCore/*.c)
file_main := $(wildcard src/main.c)
files_asm := src/*.asm
files_h := header/**/*.h
files_o := ./object_out
comp := 

BUILD_FLAGS = 
COMPILE_FLAGS = 
LINK_FLAGS =

all : link

build: 
	@${comp} ${BUILD_FLAGS}
	@echo "build success"

compile: build
	@${comp} ${COMPILE_FLAGS}
	@echo "COMPILE SUCCESS!!!"

link: compile
	@${comp} ${LINK_FLAGS}
	@echo "LINK SUCCESS!!!!"


clean:	rm  **.o
		rm *.map
		rm *.elf
		rm *.src
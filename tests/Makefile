# cross compile...
CROSS_COMPILE = 

CC = $(CROSS_COMPILE)gcc
CXX = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar

ARFLAGS = cr
RM = -rm -rf
MAKE = make

CFLAGS += -Wall\
		 -Wextra\
		 -Werror\
		 -Wconversion\
		 -Wno-unused-parameter\
		 -Wpointer-arith\
		 -Wshadow\
		 -Wwrite-strings\
		 -march=native

CPPFLAGS = -Wold-style-cast\
		   -Woverloaded-virtual

debug = y

ifeq ($(debug), y)
CFLAGS += -g
else
CFLAGS += -O2 -s
endif


#CFLAGS = -g

LDFLAGS = -rdynamic  ../commonlib.a  -lpthread

INCDIRS = ../

#CFLAGS = -g
CFLAGS += -I$(INCDIRS)

#LDFLAGS = ./../commonlib.a 


DES = xnet_thread_unittest

all:$(DES)


xnet_thread_unittest:xnet_thread_unittest.c
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)



clean:
	@echo "cleaning..."
	@$(RM) $(DES)

	@$(RM) *.o *.back *~

.PHONY: all clean

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



LDFLAGS = -rdynamic  ../commonlib.a  -lpthread

INCDIRS = ../

CFLAGS += -I$(INCDIRS)



#DES = xnet_thread xnet_log_unittest
DES = xnet_log_unittest

all:$(DES)


xnet_log_unittest:xnet_log_unittest.c
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)

xnet_thread:xnet_thread
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)



clean:
	@echo "cleaning..."
	@$(RM) $(DES)

	@$(RM) *.o *.back *~

.PHONY: all clean

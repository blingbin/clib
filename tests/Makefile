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
		 -Wold-style-cast\
		 -Woverloaded-virtual\
		 -Wpointer-arith\
		 -Wshadow\
		 -Wwrite-strings\
		 -march=native

debug = y

ifeq ($(debug), y)
CFLAGS += -g
else
CFLAGS += -O2 -s
endif



LDFLAGS = -rdynamic  ../commonlib.a  -lpthread

INCDIRS = ../

CFLAGS += -I$(INCDIRS)



DES = xnet_thread

all:$(DES)


xnet_thread:xnet_thread
	$(CC) $(CFLAGS) $^ -o $@  $(LDFLAGS)



clean:
	@echo "cleaning..."
	@$(RM) $(DES)

	@$(RM) *.o *.back *~

.PHONY: all clean

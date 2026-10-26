# ========

MK_ROOT		= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))

# ========

CC		= cc
CXX		= c++
CFLAGS 	= -Wall -Wextra -Werror -ggdb3
LFLAGS	=

# ========

.PHONY : all

all :
	-$(CC) $(CFLAGS) -o $(MK_ROOT)sample.out $(MK_ROOT)sample.c $(LFLAGS)

.PHONY : clean

clean :
	rm -f $(MK_ROOT)sample.out
	
# ========

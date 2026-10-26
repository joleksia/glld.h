# ========

MK_ROOT		= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))

# ========

CC		= cc
CXX		= c++
CFLAGS 	= -Wall -Wextra -Werror -ggdb3
LFLAGS	= -lsfml-system -lsfml-window

# ========

.PHONY : all

all :
	-$(CXX) $(CFLAGS) -o $(MK_ROOT)sample-legacy.out $(MK_ROOT)sample-legacy.cc $(LFLAGS)
	-$(CXX) $(CFLAGS) -o $(MK_ROOT)sample-modern33.out $(MK_ROOT)sample-modern33.cc $(LFLAGS)
	-$(CXX) $(CFLAGS) -o $(MK_ROOT)sample-modern46.out $(MK_ROOT)sample-modern46.cc $(LFLAGS)

.PHONY : clean

clean :
	rm -f $(MK_ROOT)sample-legacy.out
	rm -f $(MK_ROOT)sample-modern33.out
	rm -f $(MK_ROOT)sample-modern46.out
	
# ========

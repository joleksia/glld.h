# ========

MK_ROOT		= $(dir $(realpath $(firstword $(MAKEFILE_LIST))))

# ========

CC		= cc
CXX		= c++
CFLAGS 	= -Wall -Wextra -Werror -ggdb3

# ========

.PHONY : all

all :
	make all -C $(MK_ROOT)null/		CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)"
	make all -C $(MK_ROOT)glfw3/	CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)"
	make all -C $(MK_ROOT)sdl2/		CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)"
	make all -C $(MK_ROOT)sdl3/		CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)"
	make all -C $(MK_ROOT)sfml2/	CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)"
	make all -C $(MK_ROOT)sfml3/	CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)"
	make all -C $(MK_ROOT)window.h/	CC="$(CC)" CXX="$(CXX)" CFLAGS="$(CFLAGS)"

.PHONY : clean

clean :
	make clean -C $(MK_ROOT)null/
	make clean -C $(MK_ROOT)glfw3/
	make clean -C $(MK_ROOT)sdl2/
	make clean -C $(MK_ROOT)sdl3/
	make clean -C $(MK_ROOT)sfml2/
	make clean -C $(MK_ROOT)sfml3/
	make clean -C $(MK_ROOT)window.h/
	
# ========

SRCDIR	=../src
BINDIR	=bin
SRC	=$(SRCDIR)/main.cpp \
	 $(SRCDIR)/vga.cpp \
	 $(SRCDIR)/uart.cpp
ASM	=$(SRCDIR)/crt0.S
NAME	=$(BINDIR)/mkernel
CXXFLAGS= -Wall -Wextra -W -nostdinc -fno-builtin -m32 -fno-stack-protector
ASFLAGS	= --32 -mtune=i386 
LDFLAGS	= -script ./kfs.ld -nostdlib -melf_i386 --build-id=none
OBJS	= $(SRC:.cpp=.o)
OBJS	+= $(ASM:.S=.o)
RM	= rm -f
CXX	= clang++
AS 	= as
LINK	= ld

all: $(NAME)

%.o : %.S
	$(AS) $(ASFLAGS) -o $@ -c $<

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	$(LINK) $(OBJS) $(LDFLAGS) -o $(NAME)

.PHONY: all clean fclean re

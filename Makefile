SRCDIR	=src
OUTDIR	=build
BINDIR	=bin
SRC	=$(SRCDIR)/main.cpp \
	 $(SRCDIR)/vga.cpp \
	 $(SRCDIR)/uart.cpp
ASM	=$(SRCDIR)/crt0.S
NAME	=mkernel
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
	$(AS) $(ASFLAGS) -o $(OUTDIR)/$@ -c $<

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $(OUTDIR)/$@ -c $<

$(NAME): $(OBJS)
	cd $(OUTDIR) && $(LINK) $(OBJS) $(LDFLAGS) -o bin/$(NAME)

.PHONY: all clean fclean re

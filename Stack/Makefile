program_NAME := stack.out

program_C_SRCS := $(wildcard *.c)
program_CC_SRCS := $(wildcard *.cc)

program_C_OBJS := $(program_C_SRCS:.c=.o)
program_CC_OBJS := $(program_CC_SRCS:.cc=.o) ../String/string.o
program_OBJS := $(program_C_OBJS) $(program_CC_OBJS)

program_LIBRARY_DIRS :=
program_LIBRARIES :=

all: $(program_NAME)

$(program_NAME): $(program_OBJS)
	$(LINK.cc) $(program_OBJS) -o $(program_NAME)

clean:
	@- $(RM) $(program_NAME)
	@- $(RM) $(program_OBJS)

distclean: clean
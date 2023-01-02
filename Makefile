# Generated binary
BIN		:= amalgamate 
BIN2		:= pi
BIN3		:= test

# Sources
SRCS	:= $(wildcard *.cpp)
SRCS2	:= pi.c
SRCS3	:= test.c
INCS	:= $(wildcard *.h)

# Alias
ECHO	:= echo
B	:= "\033[1m"
b	:= "\033[0m"

# Include flags
INC_FLAGS	:=

# Pre-processor and compilator flags
CPP_FLAGS	:=
CXX_OPTIM	= -O2
CXX_DEBUG	= 
CXX_WARNING	= 
CXX_FLAGS	= -std=c++11 $(CXX_OPTIM) $(CXX_DEBUG) $(CXX_WARNING) $(INC_FLAGS)

# Libraries
LIBS	:= -lpthread -ldl


# Targets
.PHONY: all usage clean

all: $(BIN3) $(BIN2) $(BIN)

usage:
	@echo "make all / make $(BIN): build Amalgamate"
	@echo "make clean: clean the build"

$(BIN): $(SRCS) $(INCS)
	@$(ECHO) $(B)"Build $@"$(b)
	g++ $(CXX_FLAGS) $(CPP_FLAGS) $(SRCS) -o $@ $(OBJS) $(LIBS)


$(BIN2): $(SRCS2) $(INCS)
	@$(ECHO) $(B)"Build $@"$(b)
	g++ $(CXX_FLAGS) $(CPP_FLAGS) $(SRCS2) -o $@ $(OBJS) $(LIBS)

$(BIN3): $(SRCS3) $(INCS)
	@$(ECHO) $(B)"Build $@"$(b)
	g++ $(CXX_FLAGS) $(CPP_FLAGS) $(SRCS3) -o $@ $(OBJS) $(LIBS)


clean:
	rm -rf core *~ $(BIN) $(BIN2)  $(BIN3) 

###############################################################################
# libRNG
################################################################################

DEBUG	:= NO
CC		:= g++

DEFAULT_FLAGS   := -Wall -I${SRC_DIR}
DEBUG_FLAGS	:= ${DEFAULT_FLAGS} -Wno-format -g -DDEBUG
RELEASE_FLAGS	:= ${DEFAULT_FLAGS} -Wno-unknown-pramas -Wno-format -O3

SOFLAGS := -fPIC -shared
SHARED_OBJECT := librng.so

ifeq (YES, ${DEBUG})
    CFLAGS := ${DEBUG_FLAGS}
else
    CFLAGS := ${RELEASE_FLAGS}
endif

BUILD_DIR   := build
SRC_DIR	    := src
LIBRNG_SRCS := rng.cpp cmwc.cpp kiss.cpp jkiss.cpp jlkiss64.cpp jkiss32.cpp superkiss.cpp xor32.cpp xor64.cpp buffered_rng.cpp scg.cpp
LIBRNG_OBJS := $(addsuffix .o, $(basename $(LIBRNG_SRCS)))
SRCS := $(addprefix $(SRC_DIR)/, $(LIBRNG_SRCS))
OBJS := $(addprefix $(BUILD_DIR)/, $(LIBRNG_OBJS))

all: $(OBJS) $(SHARED_OBJECT)

$(SHARED_OBJECT): $(OBJS)
	$(CC) $(CFLAGS) $(SOFLAGS) -o $@ $(OBJS)
clean:
	rm -rf $(BUILD_DIR)

$(OBJS): $(SRCS) | $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o : $(SRC_DIR)/%.cpp
	${CC} $(CFLAGS) -c $< -o $@

%.cpp : %.h

include make/external.mk
include make/sys.mk
include make/scripts.mk

CC=g++
CFLAGS=-Wall -c -g
LDFLAGS=
INCLDS=$(EXT_INCLDS) -I.
LIBDIRS=$(EXT_LIBDIRS)
LIBS=$(EXT_LIBS)
OUTPUT=$(BINDIR)/map-generator

SOURCES:=$(wildcard *.cpp \
                    components/*.cpp \
										image/*.cpp \
										)

OBJECTS=$(SOURCES:.cpp=.o)

ALL=$(OBJECTS)

all: $(ALL)
	$(PRE_LINK)
	$(CC) $(LDFLAGS) $(LIBDIRS) $(LIBS) $(OBJECTS) -o $(OUTPUT)
	$(POST_LINK)

.cpp.o:
	$(PRE_COMPILE)
	$(CC) $(CFLAGS) $(INCLDS) $< -o $@
	$(POST_COMPILE)

clean:
	$(CLEANUP)

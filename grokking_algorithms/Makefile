######### Makefile COMMON ########  
EXTENSION = c
CC = gcc
EXE = main
SUBDIR = src

CPPFLAGS += -I /home/kouwq/Makefile/grokking_algorithms/inc
#LDFLAGS +=
#CFLAGS += -g -Wall
CXX_SOURCES = $(foreach dir,$(SUBDIR), $(wildcard $(dir)/*.$(EXTENSION)))
CXX_OBJECTS = $(patsubst  %.$(EXTENSION), %.o, $(CXX_SOURCES))
DEP_FILES  = $(patsubst  %.$(EXTENSION), %.d, $(CXX_SOURCES))

$(EXE): $(CXX_OBJECTS)
	$(CC) $(CXX_OBJECTS) -o $(EXE)

%.o: %.$(EXTENSION)
	$(CC) -c -MMD $(CPPFLAGS) $< -o $@

#ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEP_FILES)
#endif

.PHONY:clean
clean:
	-rm  -f  $(CXX_OBJECTS)  $(DEP_FILES)  $(EXE)

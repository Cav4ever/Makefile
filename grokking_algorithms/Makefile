######### Makefile COMMON ########  
EXTENSION = c
CC = gcc
EXE = main
SUBDIR = src
OBJ = obj
DEP = dep

CPPFLAGS += -I /home/kouwq/Makefile/grokking_algorithms/inc
#LDFLAGS +=
#CFLAGS += -g -Wall
CXX_SOURCES = $(foreach dir,$(SUBDIR), $(wildcard $(dir)/*.$(EXTENSION)))
CXX_OBJECTS = $(patsubst  %.$(EXTENSION), $(OBJ)/%.o, $(notdir $(CXX_SOURCES)))
DEP_FILES  = $(patsubst  %.$(EXTENSION), $(DEP)/%.d, $(notdir $(CXX_SOURCES)))

$(EXE): $(CXX_OBJECTS)
	$(CC) $(CXX_OBJECTS) -o $(EXE)

$(OBJ)/%.o: $(SUBDIR)/%.$(EXTENSION)
	$(CC) -c $(CPPFLAGS) $< -o $@

$(DEP)/%.d: $(SUBDIR)/%.$(EXTENSION)
	$(CC) $(CPPFLAGS) -MM $< | sed -e 1's,^,$(OBJ)/,' > $@

ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEP_FILES)
endif

.PHONY:clean
clean:
	-rm  -f  $(CXX_OBJECTS)  $(DEP_FILES)  $(EXE)

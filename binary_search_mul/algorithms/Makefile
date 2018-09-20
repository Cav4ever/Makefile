######### Makefile MLD ########  
EXTENSION = c
CC = gcc
SUBDIR = src
OBJ = obj
DEP = dep
#CXXFLAGS:编译选项, LDFLAGS:链接选项  
CXXFLAGS += -I /home/kouwq/Makefile/binary_search_mul/algorithms/include
#LDFLAGS +=

CXX_SOURCES =$(foreach dir,$(SUBDIR), $(wildcard $(dir)/*.$(EXTENSION)))
CXX_OBJECTS=$(patsubst  %.$(EXTENSION), ${OBJ}/%.o, $(notdir $(CXX_SOURCES)))
DEP_FILES  =$(patsubst  %.$(EXTENSION), ${DEP}/%.d, $(notdir $(CXX_SOURCES)))

.PHONY:all
all: $(CXX_OBJECTS)

${OBJ}/%.o: ${SUBDIR}/%.$(EXTENSION)
	$(CC)  -c $(CXXFLAGS)  $<  -o  $@

${DEP}/%.d: ${SUBDIR}/%.$(EXTENSION)
	$(CC) $(CXXFLAGS) -MM $< | sed -e 1's,^,$(OBJ)/,' > $@

ifneq "$(MAKECMDGOALS)" "clean"
-include $(DEP_FILES)
endif

.PHONY:clean
clean:
	-rm  -f  $(CXX_OBJECTS)  $(DEP_FILES)
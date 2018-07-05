######### 标准Makefile Lv1 ########  
EXTENSION=c
CC=gcc
EXE=main
SUBDIR=src
OBJ = ./obj
DEP = ./dep

#CXXFLAGS:编译选项, LDFLAGS:链接选项  
CXXFLAGS += -I /home/nsqat/test/grokking_algorithms/inc
#LDFLAGS +=

CXX_SOURCES =$(foreach dir,$(SUBDIR), $(wildcard $(dir)/*$(EXTENSION)))
CXX_OBJECTS=$(patsubst  %.$(EXTENSION), ${OBJ}/%.o, $(notdir $(CXX_SOURCES)))
DEP_FILES  =$(patsubst  %.$(EXTENSION), ${DEP}/%.d, $(notdir $(CXX_SOURCES)))

$(EXE): $(CXX_OBJECTS)
	$(CC)  $(CXX_OBJECTS) -o $(EXE)

${OBJ}/%.o: ${SUBDIR}/%.$(EXTENSION)
	$(CC)  -c $(CXXFLAGS)  $<  -o  $@

${DEP}/%.d: ${SUBDIR}/%.$(EXTENSION)
	$(CC) $(CXXFLAGS) -MM $< | sed -e 1's,^,$(OBJ)/,' > $@

-include ${DEP_FILES}

clean:
	rm  -rf  $(CXX_OBJECTS)  $(DEP_FILES)  $(EXE)
######### 标准Makefile Lv1 ########  
EXTENSION=c
CC=gcc
EXE=../target/main
SUBDIR=src
OBJ = ./obj
DEP = ./dep

SUBDIR_A=../algorithms/src
OBJ_A = ../algorithms/obj


#CXXFLAGS:编译选项, LDFLAGS:链接选项  
CXXFLAGS += -I /home/kouwq/test/binary_search_mul/algorithms/include
#LDFLAGS +=

CXX_SOURCES =$(foreach dir,$(SUBDIR), $(wildcard $(dir)/*.$(EXTENSION)))
CXX_OBJECTS=$(patsubst  %.$(EXTENSION), ${OBJ}/%.o, $(notdir $(CXX_SOURCES)))
DEP_FILES  =$(patsubst  %.$(EXTENSION), ${DEP}/%.d, $(notdir $(CXX_SOURCES)))

CXX_SOURCES_A =$(foreach dir,$(SUBDIR_A), $(wildcard $(dir)/*.$(EXTENSION)))
CXX_OBJECTS_A=$(patsubst  %.$(EXTENSION), ${OBJ_A}/%.o, $(notdir $(CXX_SOURCES_A)))

CXX_OBJECTS_T=$(CXX_OBJECTS)$(CXX_OBJECTS_A)

$(EXE): $(CXX_OBJECTS_T)
	$(CC)  $(CXX_OBJECTS_T) -o $(EXE)

${OBJ}/%.o: ${SUBDIR}/%.$(EXTENSION)
	$(CC)  -c $(CXXFLAGS)  $<  -o  $@

${DEP}/%.d: ${SUBDIR}/%.$(EXTENSION)
	$(CC) $(CXXFLAGS) -MM $< | sed -e 1's,^,$(OBJ)/,' > $@

-include ${DEP_FILES}

clean:
	rm  -rf  $(CXX_OBJECTS)  $(DEP_FILES)
#最外层的makefile负责创建相关目录和进入每个子目录去make

PWD  := $(shell pwd)
SUBDIRS = algorithms main

.PHONY:all
all:
	@list='$(SUBDIRS)';for subdir in $$list; do \
		make -C $$subdir M=$(PWD); \
	done
.PHONY:clean
clean:
	@list='$(SUBDIRS)'; for subdir in $$list; do \
		make -C $$subdir M=$(PWD) clean;\
	done
	rm -f ./target/*
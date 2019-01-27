OUTPUTDIR = build
SRCDIR = src
EXECUTABLE = Project1

all:
	g++ -c -o $(OUTPUTDIR)/Project1.o $(SRCDIR)/Project1.cpp
	g++ -o $(OUTPUTDIR)/$(EXECUTABLE) $(OUTPUTDIR)/*.o
	mv $(OUTPUTDIR)/$(EXECUTABLE) ./

TOPTARGETS := all test clean

SUBDIRS := $(wildcard src/*/.)

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)

clean:
	rm -f build/*
	rm Project1

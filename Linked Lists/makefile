OUTPUTDIR = build
TESTDIR = tests
SRCDIR = src
EXECUTABLE = LinkedList

all:
	g++ -c -o $(OUTPUTDIR)/$(EXECUTABLE).o $(SRCDIR)/$(EXECUTABLE).cpp
	g++ -o $(OUTPUTDIR)/$(EXECUTABLE) $(OUTPUTDIR)/*.o
	mv $(OUTPUTDIR)/$(EXECUTABLE) ./

TOPTARGETS := all test clean

SUBDIRS := $(wildcard src/*/.)

$(TOPTARGETS): $(SUBDIRS)
$(SUBDIRS):
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: $(TOPTARGETS) $(SUBDIRS)

clean:
	rm -f $(OUTPUTDIR)/*
	rm -f $(EXECUTABLE)
	rm -f $(TESTDIR)/*

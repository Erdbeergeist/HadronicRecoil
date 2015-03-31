#enclose multiple programs in quotes
PROGRAMS='$(subst .cxx,, $(shell cd ./; ls *.cxx 2>/dev/null))'
SRCS = $(shell ls *.cxx 2>/dev/null)
OBJ= $(foreach PP, $(PROGRAMS), $(PP).o)

LD=g++
CXX=g++

INCLUDEFLAGS = -I./ 

LD_FLAGS = -lmycode

ROOTLIBS = `root-config --libs` -lFoam -lMinuit -lTreePlayer
ROOTCFLAGS = -ggdb $(shell root-config --cflags)
ROOTGLIBS = -Wl,--no-as-needed $(shell root-config --glibs)
PWD = $(shell pwd)

.cxx.o:
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDEFLAGS) -c $<

all: $(PROGS)
	$(CXX) Preparation.cxx $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDEFLAGS) -c $<
	$(LD) -o Preparation Preparation.o $(ROOTLIBS)
clean:
	export PROGS=$(PROGRAMS);
	-rm Preparation *.o *~

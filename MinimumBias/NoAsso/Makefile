PROGRAMS='$(subst .cxx,, $(shell cd ./; ls *.cxx 2>/dev/null))'
SRCS = $(shell ls *.cxx 2>/dev/null)
OBJ= $(foreach PP, $(PROGRAMS), $(PP).o)

LD=g++
CXX=g++

INCLUDEFLAGS = -I./ 
CXXFLAGS = 
LD_FLAGS = -lmycode

ROOTLIBS = `root-config --libs` -lFoam -lMinuit -lTreePlayer
ROOTCFLAGS = -ggdb $(shell root-config --cflags)
ROOTGLIBS = -Wl,--no-as-needed $(shell root-config --glibs)
PWD = $(shell pwd)

.cxx.o:
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDEFLAGS) -c $<


Analysis: noasso.cxx
	$(CXX) -o noasso $(CXXFLAGS) $(ROOTCFLAGS) $(INCLUDEFLAGS) noasso.cxx  $(ROOTGLIBS)
	

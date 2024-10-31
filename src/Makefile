# Directories and Compiler
IDIR = ../include
IEXTRADIR = /data/john/libs/include
CXX = g++
CXXFLAGS = -I$(IDIR) -I$(IEXTRADIR) -g -fsanitize=address -static-libasan

# Define DEBUG in the source if we are debugging
ifeq ($(DEBUG), 1)
    CXXFLAGS += -DDEBUG
endif

ODIR = obj
LDIR = -L/data/john/libs/lib

LIBS = -lm -lpthread -lzbd

# Headers and Objects
_DEPS = gczns.hpp util.hpp Disk.hpp ZNSSSD.hpp SSD.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = gczns.o Disk.o SSD.o ZNSSSD.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rules for object files
$(ODIR)/%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Linking final executable
gczns: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS) $(LDIR)

.PHONY: clean

# Clean command
clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~

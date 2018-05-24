APP = $(PWD)


INCL = /usr/local/include  
LDFLAGS = -L /usr/local/lib -L /usr/lib -lpthread -lgtest -lglog -lgflags -ldl 

CC=g++
CXXFLAGS = -std=c++14 -I $(INCL) -I ./ -DGTEST_HAS_TR1_TUPLE=0 -DGTEST_LANG_CXX11=1 -fPIC -Wall

EXE = main
OBJS = main.o feature_context.o

.PHONY : all clean
all: $(EXE)

.cc.o:
	$(CC) $(CXXFLAGS) -c $< -o $@ $(INCL) ./

$(EXE): $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(EXE) $(OBJS)

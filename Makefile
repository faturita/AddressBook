CC = g++
CFLAGS = -std=c++14 -w -g -Wall -fpermissive
PROG = addressbook


SCS = src/addressbookclass.cpp src/addressbookentry.cpp src/commandline.cpp 

SSRC = $(SCS) src/addressbook.cpp 
OBJS = $(SSRC:.cpp=.o)

TCSRCS = $(SCS) src/tests/tester.cpp src/tests/testcase.cpp src/tests/testcase_$(TC).cpp
TCOBJS = $(TCSRCS:.cpp=.o)

all: $(PROG)


testcase:	$(TCOBJS)
	@echo "Building test cases"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)


$(PROG):	$(OBJS)
	@echo "Object files are $(OBJS)"
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
    
.cpp.o:		$(SRCS)		
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(PROG)
	rm -f testcase


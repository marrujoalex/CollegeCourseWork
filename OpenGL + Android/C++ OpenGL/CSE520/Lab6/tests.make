#sample Makefile for using OpenGL in Linux
                                                                                
PROG    = lab6b
CFLAGS  = -w -s -O2 -ansi -DSHM
XLIBS   = -lX11 -lXext -lXmu -lXext -lXmu -lXt -lXi -lSM -lICE
LIBS    = -lglut -lGLU -lGL -lGLEW
INCLS   = -I/usr/X11R/include -I/share/mesa/include
LIBDIR  = -L/usr/X11/lib -L/usr/X11R6/lib
#source codes
SRCS = tempcolor.cpp
#substitute .cpp by .o to obtain object filenames
OBJS = $(SRCS:.cpp=.o)
                                                                                
#$< evaluates to the target's dependencies,
#$@ evaluates to the target
                                                                                
$(PROG): $(OBJS)
	g++ -o $@ $(OBJS)  $(LIBDIR) $(LIBS) $(XLIBS)
$(OBJS):
	g++ -c  $*.cpp $(INCLS)
                                                                                
clean:
	rm $(OBJS) $(PROG)


#
# Makefile
# moondark, 2013-12-14 19:48
#

CC=g++
CFLAGS= -g -w `pkg-config opencv --libs --cflags opencv`

all: \
	saliency

saliency: \
	maxflow-v3.01/graph.cpp \
	maxflow-v3.01/maxflow.cpp \
	fresaliency.cpp \
	fresalgc.cpp \
	saliency.cpp
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm saliency


# vim:ft=make
#


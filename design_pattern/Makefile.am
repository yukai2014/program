bin_PROGRAMS = design_pattern

design_pattern_SOURCES = all_in_one.cpp 		meyers_singleton.cpp \
						meyers_singleton.h 		meyers_singleton_test.h
	
design_pattern_CPPFLAGS= -fPIC
	
design_pattern_LDFLAGS =-lc -lm -lrt -lpthread

LDADD = ../common/libcommon.a \
		./command/libcommand.a
	
SUBDIRS = command
DIST_SUBDIRS = command
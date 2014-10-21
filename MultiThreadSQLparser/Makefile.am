bin_PROGRAMS = parser

parser_SOURCES = function.cpp \
	lex.yy.cpp 		sql.tab.cpp \
	sql.tab.hpp 	sql_node_struct.h \
	testyu2.cpp
	
parser_CPPFLAGS= -g -fPIC
	
parser_LDFLAGS =-lc -lm -lrt -lpthread  
bin_PROGRAMS = tset

tset_SOURCES = 		false_sharing.cpp \
	select.cpp 		test.cpp	\
	MemoryLayoutOfClass.h
	
test_CPPFLAGS = -fPIC  -g\
-I${BOOST_HOME}/boost/serialization 
	
tset_LDFLAGS = -lpthread -lboost_serialization

tset_LDADD = \
	${BOOST_HOME}/stage/lib/libboost_serialization.a \
	${BOOST_HOME}/stage/lib/libboost_serialization.so 
	
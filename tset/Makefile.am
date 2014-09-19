bin_PROGRAMS = tset

tset_SOURCES = 		false_sharing.cpp \
	select.cpp 		tset.cpp
	
test_CPPFLAGS = -fPIC \
-I${BOOST_HOME}/boost/serialization 
	
tset_LDFLAGS = -lpthread -g -lboost_serialization

tset_LDADD = \
	${BOOST_HOME}/stage/lib/libboost_serialization.a \
	${BOOST_HOME}/stage/lib/libboost_serialization.so 
	
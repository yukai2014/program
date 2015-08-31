AC_INIT([program], [0.1], [yukai])
AM_INIT_AUTOMAKE([-Wall foreign])
AC_PROG_LIBTOOL
CPPFLAGS="-w -O0 -DTHERON_XS -D__STDC_CONSTANT_MACROS -D__STDC_LIMIT_MACROS"
CXXFLAGS=${CXXFLAGS="-g  -std=c++11"}
AC_PROG_CXX
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
  Makefile
  common/Makefile
  MultiThreadSQLparser/Makefile 
  Network/Makefile
  SimpleThreadPool/Makefile 
  test/Makefile 
  MemoryPool/Makefile
  readline/Makefile
  design_pattern/Makefile
])
AC_OUTPUT


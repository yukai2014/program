AC_INIT([program], [0.1], [yukai])
AM_INIT_AUTOMAKE([-Wall foreign])
AM_PROG_AR
AC_PROG_LIBTOOL
CPPFLAGS="-w -O0"
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
  design_pattern/command/Makefile
])
AC_OUTPUT


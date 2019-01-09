AC_INIT
AC_CONFIG_FILES([Makefile])
AC_LANG([C++])
AC_SUBST([TESTFLAGS], [TESTFLAGS])
AC_CHECK_PROGS([llvmcov], [llvm-cov-3.9 llvm-cov-3.8 llvm-cov-3.6 llvm-cov-3.9 llvm-cov-3.0 llvm-cov], [] )
AX_CHECK_COMPILE_FLAG([-std=c++11], [CXXFLAGS="$CXXFLAGS -std=c++11"], [exit 1])
AX_CHECK_COMPILE_FLAG([-O0], [TESTFLAGS="-O0"])
AX_CHECK_COMPILE_FLAG([-fprofile-arcs], [TESTFLAGS="$TESTFLAGS -fprofile-arcs"])
AX_CHECK_COMPILE_FLAG([-ftest-coverage], [TESTFLAGS="$TESTFLAGS -ftest-coverage"])
AX_CHECK_COMPILE_FLAG([-Wall], [CXXFLAGS="$CXXFLAGS -Wall"])
AC_OUTPUT

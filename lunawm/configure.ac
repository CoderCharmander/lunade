AC_INIT([lunawm], [0.1], [deak311@outlook.hu])
AM_INIT_AUTOMAKE([-Wall])

AC_PROG_CC
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
Makefile
src/Makefile
])

AC_CHECK_HEADER([X11/Xlib.h],[],[AC_MSG_ERROR([can't use Xlib.h])])
AC_CHECK_LIB([X11],[XOpenDisplay],[],[
echo X11 library required.
exit -1
])

AC_OUTPUT

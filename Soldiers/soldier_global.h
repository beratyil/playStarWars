#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(SOLDIER_LIB)
#  define SOLDIER_EXPORT Q_DECL_EXPORT
# else
#  define SOLDIER_EXPORT Q_DECL_IMPORT
# endif
#else
# define SOLDIER_EXPORT
#endif

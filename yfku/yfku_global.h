#ifndef YFKU_GLOBAL_H
#define YFKU_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(YFKU_LIBRARY)
#  define YFKUSHARED_EXPORT Q_DECL_EXPORT
#else
#  define YFKUSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // YFKU_GLOBAL_H

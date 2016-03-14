TARGET =PhysicsLib
QT+=testlib
CONFIG+=c++11
OBJECTS_DIR=obj
SOURCES+=$$PWD/src/main.cpp\
         $$PWD/src/Timer.cpp

HEADERS+=$$PWD/include/Timer.h

INCLUDEPATH+=$$PWD/include

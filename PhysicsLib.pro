TARGET =PhysicsLib
QT+=testlib
CONFIG+=c++11
OBJECTS_DIR=obj
SOURCES+=$$PWD/src/main.cpp\
         $$PWD/src/Timer.cpp\
         $$PWD/src/Distance.cpp

HEADERS+=$$PWD/include/Timer.h\
         $$PWD/include/Distance.h

INCLUDEPATH+=$$PWD/include

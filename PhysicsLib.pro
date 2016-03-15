#Specifies the exe name
TARGET =PhysicsLib

#Where to put .o files
OBJECTS_DIR=obj

#core Qt Libs to use. Can add more if needed
QT+=testlib

#
CONFIG+=c++11

#Include all .cpp files needed from src directory
SOURCES+=$$PWD/src/main.cpp\
         $$PWD/src/Timer.cpp\
         $$PWD/src/Distance.cpp

#Include all .h files from include directory
HEADERS+=$$PWD/include/Timer.h\
         $$PWD/include/Distance.h

#Add the include dir into the search path for Qt and make
INCLUDEPATH += ./include

#Specifies the exe name
TARGET =PhysicsLib

#Where to put .o files
OBJECTS_DIR=obj

#core Qt Libs to use. Can add more if needed
QT+=gui opengl core

# To support 4.8 and 5 this will set a flag for some of the mac stuff mainly in the types.h file for the setMacVisual which is native in Qt5
isEqual(QT_MAJOR_VERSION, 5) {
        cache()
        DEFINES +=QT5BUILD
}
# where to put moc auto generated files
MOC_DIR=moc

CONFIG+=c++11

#Include all .cpp files needed from src directory
SOURCES+=$$PWD/src/main.cpp\
         $$PWD/src/Body.cpp\
         $$PWD/src/NGLScene.cpp\
         $$PWD/src/Emitter.cpp\
         $$PWD/src/Particle.cpp\
         $$PWD/src/ParticleFactory.cpp\





#Include all .h files from include directory
HEADERS+=$$PWD/include/NGLScene.h\
         $$PWD/include/Emitter.h\
         $$PWD/include/Particle.h\
         $$PWD/include/Body.h\
         $$PWD/include/ParticleFactory.h\



#Add the include dir into the search path for Qt and make

INCLUDEPATH +=./include

# Where our exe is going to live (root of project)
DESTDIR=./

# Add the glsl shader files
OTHER_FILES+= shaders/*.glsl \

# were are going to default to a console app
CONFIG += console

# Each command added needs a ; as it will be run as a single line
# First check if we are shadow building or not easiest way is to check out against current
!equals(PWD, $${OUT_PWD}){
        copydata.commands = echo "creating destination dirs" ;
        # now make a dir
        copydata.commands += mkdir -p $$OUT_PWD/shaders ;
        copydata.commands += echo "copying files" ;
        # then copy the files
        copydata.commands += $(COPY_DIR) $$PWD/shaders/* $$OUT_PWD/shaders/ ;
        # now make sure the first target is built before copy
        first.depends = $(first) copydata
        export(first.depends)
        export(copydata.commands)
        # now add it as an extra target
        QMAKE_EXTRA_TARGETS += first copydata
}


#include UseNGL.pri to use NGL
NGLPATH=$$(NGLDIR)
isEmpty(NGLPATH){
       message("including $HOME/NGL")
      include($(HOME)/NGL/UseNGL.pri)
                }
else{
       message("Using custom NGL location")
      include($(NGLDIR)/UseNGL.pri)
 }

#Test

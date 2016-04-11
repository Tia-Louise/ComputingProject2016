#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>
#include <QtGui/QGuiApplication>

///INCLUDING HEADERS
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Body.h>
#include "NGLScene.h"



///MAIN FUNCTION TESTING
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main(int argc, char **argv)
{

///NGL Window
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  {
    QGuiApplication app(argc, argv);

    QSurfaceFormat format;// create an OpenGL format specifier

    format.setSamples(4);// set the number of samples for multisampling.We will need to enable glEnable(GL_MULTISAMPLE); once we have a context
    #if defined( __APPLE__)
      format.setMajorVersion(4);
      format.setMinorVersion(1);
    #else
      format.setMajorVersion(4);
      format.setMinorVersion(3);
    #endif

    format.setProfile(QSurfaceFormat::CoreProfile);// Set to CoreProfile OpenGL so we can't use and old Immediate mode GL
    format.setDepthBufferSize(24);// Set the depth buffer to 24 bits
    NGLScene window;// Create window
    window.setFormat(format);//Set OpenGL format
    std::cout<<"Profile is "<<format.majorVersion()<<" "<<format.minorVersion()<<"\n";//Query the version to test if it worked.
    window.resize(1000, 1000);//Set window size
    window.show();

    return app.exec();


  }



}


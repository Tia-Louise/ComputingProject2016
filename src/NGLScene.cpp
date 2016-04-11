#include <QMouseEvent>
#include <QGuiApplication>

#include <NGLScene.h>
#include <ngl/Camera.h>
#include <ngl/Light.h>
#include <ngl/Material.h>
#include <ngl/NGLInit.h>
#include <ngl/VAOPrimitives.h>
#include <ngl/ShaderLib.h>
#include <Particle.h>


const static float INCREMENT=0.01;//Increment for x/y translation with mouse movement
const static float ZOOM =0.1;//Increment for x/y zoom with wheel movement


NGLScene::NGLScene()
{
  // re-size the widget to that of the parent (in this case the GLFrame passed in on construction.

  setTitle("Particle System");

  m_rotate=false;

  // mouse rotation values set to 0
  m_spinXFace=0;
  m_spinYFace=0;
}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


NGLScene::~NGLScene()
{
  std::cout<<"Shutting down NGL, removing VAO's and Shaders\n";
}

///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::resizeGL(QResizeEvent *_event)
{
  m_width=_event->size().width()*devicePixelRatio();
  m_height=_event->size().height()*devicePixelRatio();

  // Set the camera size values as the screen size has changed.
  m_cam.setShape(45.0f,(float)width()/height(),0.05f,350.0f);
}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::resizeGL(int _w , int _h)
{
  m_cam.setShape(45.0f,(float)_w/_h,0.05f,350.0f);
  m_width=_w*devicePixelRatio();
  m_height=_h*devicePixelRatio();
}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void NGLScene::initializeGL()
{
  // Need to initialise the NGL lib which will load all of the OpenGL functions, this must be done once a valid GL context is obtained but before any GL commands are called. If not done the program will crash.
  ngl::NGLInit::instance();
  glClearColor(0.0f, 0.0f, 0.0f, 0.0f);// White Background
  glEnable(GL_DEPTH_TEST);// enable depth testing for drawing
  glEnable(GL_MULTISAMPLE);// enable multisampling for smoother drawing

  //A basic camera from the graphics library will be created. This is a static camera so therefore only needs to be set once.
  //Values for the camera position
  ngl::Vec3 from(0,5,18);
  ngl::Vec3 to(0,0,0);
  ngl::Vec3 up(0,1,0);

  m_cam.set(from,to,up);
  m_cam.setShape(40,(float)720.0/576.0,0.5,150);  // Set the shape using FOV 45 Aspect Ratio based on Width and Height. The final two values are near and far clipping planes of 0.5 and 10.

  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();

  prim->createSphere("sphere",0.1,10);
  m_wind.set(1,1,1);
  m_emitter.reset(new Emitter(ngl::Vec3(0,0,0),400,&m_wind));
  m_emitter->setCam(&m_cam);

  m_text.reset( new ngl::Text(QFont("Arial",14)));
  m_text->setScreenSize(width(),height());

  // As re-size is not explicitly called this is neccasary
  glViewport(0,0,width(),height());
  m_particleTimer=startTimer(20);



}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::paintGL()
{
  // Grab an instance of the shader manager and clear the screen and depth buffer.

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glViewport(0,0,m_width,m_height);
  m_emitter->draw();
  m_text->setColour(0.5,0.5,0.5);

  QString text=QString("Wind Vector  %1 %2 %3").arg(m_wind.m_x).arg(m_wind.m_y).arg(m_wind.m_z);
  m_text->renderText(400,10,text);
  m_text->renderText(400,30,QString("Gravity = 9.81 m/s"));
  text.sprintf("Number of particles = %d",m_emitter->getNumParticles());
  m_text->renderText(400,50,text);

  m_text->setColour(0.5,0.5,0.5);
  m_text->renderText(10,10,QString("ESC to close"));
  m_text->renderText(10,30,QString("F/N to toggle full screen"));

  m_text->setColour(1,1,1);
  m_text->renderText(10,810,QString("1/2 to add and remove particles.(MAX 400)"));
  m_text->renderText(10,830,QString("I/O to toggle spread of particles"));
  m_text->renderText(10,850,QString("SPACE to clear all particles"));

  m_text->renderText(10,880,QString("ARROW KEYS to toggle wind direction"));
  m_text->renderText(10,900,QString("BACKSPACE to reset wind"));



}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::addParticles()
{
 m_emitter->addParticle();

}

///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//never start timer in compiler, always in the GL else it will crash
void NGLScene::timerEvent(QTimerEvent *_event)
{
  if(_event->timerId() ==   m_particleTimer)
  {
    m_emitter->update();
    update();
  }


    // Re-draw GL
}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::mouseMoveEvent (QMouseEvent * _event)
{
  // Note The method buttons() is the button state when event was called. This is different from button() which is used to check which button was pressed when the mousePress/Release event is generated.

  // Left mouse translate code
  if(m_rotate && _event->buttons() == Qt::LeftButton)
  {
    int diffx=_event->x()-m_origX;
    int diffy=_event->y()-m_origY;
    m_spinXFace += (float) 0.5f * diffy;
    m_spinYFace += (float) 0.5f * diffx;
    m_origX = _event->x();
    m_origY = _event->y();
    update();

  }
  // Right mouse translate code
  else if(m_translate && _event->buttons() == Qt::RightButton)
  {
    int diffX = (int)(_event->x() - m_origXPos);
    int diffY = (int)(_event->y() - m_origYPos);
    m_origXPos=_event->x();
    m_origYPos=_event->y();
    m_modelPos.m_x += INCREMENT * diffX;
    m_modelPos.m_y -= INCREMENT * diffY;
    update();

   }

}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::mousePressEvent ( QMouseEvent * _event)
{
  // This method is called when the mouse button is pressed.In this case we store the value where the mouse was clicked (x,y) and set the Rotate flag to true.
  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  // Left mouse translate mode
  if(_event->button() == Qt::LeftButton)
  {
    m_origX = _event->x();
    m_origY = _event->y();
    m_rotate =true;
  }
  // Right mouse translate mode
  else if(_event->button() == Qt::RightButton)
  {
    m_origXPos = _event->x();
    m_origYPos = _event->y();
    m_translate=true;
  }

}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::mouseReleaseEvent ( QMouseEvent * _event )
{
  // This event is called when the mouse button is released.Rotate is set to false
  //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

  // Left mouse translate mode
  if (_event->button() == Qt::LeftButton)
  {
    m_rotate=false;
  }

  // Right mouse translate mode
  if (_event->button() == Qt::RightButton)
  {
    m_translate=false;
  }

}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::wheelEvent(QWheelEvent *_event)
{
  // Check the difference of the wheel position (0 means no change)
  if(_event->delta() > 0)
  {
    m_modelPos.m_z+=ZOOM;
  }
  else if(_event->delta() <0 )
  {
    m_modelPos.m_z-=ZOOM;
  }
  update();

}


///---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void NGLScene::keyPressEvent(QKeyEvent *_event)
{
  // this method is called every time the main window recives a key event.We then switch on the key value and set the camera in the GLWindow
  switch (_event->key())
  {
    case Qt::Key_Escape : QGuiApplication::exit(EXIT_SUCCESS); break;// escape key to quit
    case Qt::Key_F : showFullScreen(); break;//Full screen
    case Qt::Key_N : showNormal(); break;//Windowed Screen
    case Qt::Key_1 : addParticles(); break;//Add particles into system
    case Qt::Key_2 : m_emitter->removeParticle(); break;//Remove last particle
    case Qt::Key_Space : m_emitter->clearParticles(); break;//Clear all particles
    case Qt::Key_Up : m_wind.m_y+=0.1; break;//Increase wind in y direction
    case Qt::Key_Down : m_wind.m_y-=0.1; break;//Decrease wind in y direction
    case Qt::Key_Left : m_wind.m_x+=0.1; break;//Increases wind in x direction
    case Qt::Key_Right : m_wind.m_x-=0.1; break;//Decreases wind in x direction
    case Qt::Key_I : m_wind.m_z+=0.1; break;//Increases spread of particles
    case Qt::Key_O : m_wind.m_z-=0.1; break;//Decreases spread of particles
    case Qt::Key_Backspace : m_wind.set(1,1,1); break;//Reset
    default : break;
  }
  // finally update the GLWindow and re-draw
    update();
}






#ifndef NGLSCENE_H__
#define NGLSCENE_H__
#include <ngl/Camera.h>
#include <ngl/BBox.h>
#include <ngl/Colour.h>
#include <ngl/Light.h>
#include <ngl/Text.h>
#include "Emitter.h"
#include <QOpenGLWindow>
#include <QTime>
#include <memory>

class NGLScene : public QOpenGLWindow
{
  Q_OBJECT
  public:

    NGLScene();//constructor
   ~NGLScene();//deconstructor

    void initializeGL();//is called once the window is created and has valid GL context
    void paintGL();//Called everytime we want to draw the scene
    void resizeGL(QResizeEvent *_event);//Called everytime we rezie the window. Qt 5.5.1 must have this implemented and uses it
    void resizeGL(int _w, int _h);


private:


    int m_spinXFace;//Used to store the x rotation mouse value
    int m_spinYFace;//Used to store y rotation mouse value
    bool m_rotate;//Flag to indicate if the mouse button is pressed when dragging
    bool m_translate;//flag to indicate if the Right mouse button is pressed when dragging
    int m_origX;//previous x mouse value
    int m_origY;//previous y mouse value
    int m_origXPos;//previous x mouse value for Position changes
    int m_origYPos;//previous y mouse value for Position changes
    int m_width;//Window width
    int m_height;//Window height
    ngl::Mat4 m_mouseGlobalTX;
    ngl::Camera m_cam;//Camera
    ngl::Vec3 m_modelPos;//Model position for mouse movement
    int m_fpsTimer;//Flag for the fps T imer
    std::unique_ptr<Emitter> m_emitter;//The fps to draw
    ngl::Vec3 m_emitterPos;//Emitter position to update
    std::vector <Particle> m_particleArray;

    int m_particleTimer;//Particle update timer
    ngl::Vec3 m_wind;//Wind vector
    std::unique_ptr<ngl::Text> m_text;
    std::unique_ptr<ngl::BBox>m_bbox;//Bounding box to contain the spheres

    bool m_animate;//Flag to indicate if animation is active or not
    void updateScene();
    void addParticles();//Add a new particle
    void loadMatricesToShader();//Method to load transform matrices to the shader
    void keyPressEvent(QKeyEvent *_event);//Qt Event called when a key is pressed. _event the Qt event to query for size etc.
    void mouseMoveEvent (QMouseEvent * _event );//This method is called everytime a mouse is moved
    void mousePressEvent ( QMouseEvent *_event);// This method is called everytime the mouse button is pressed. Inherited from QObject and overridden here. _event the Qt event structure
    void mouseReleaseEvent ( QMouseEvent *_event );//This method is called everytime the mouse button is released. Inhertited from QObject and overridden here. _event from the Qt Event structure.
    void wheelEvent( QWheelEvent *_event);//This method is called everytime the mouse wheel is moved and inherited from QObject and overridden here. _event the Qt Event structure
    void timerEvent(QTimerEvent *_event);
    void updateEmitterPos(float _dx,float _dy,float _dz);
    void checkCollisions();
    void BBoxCollision();//Check the bounding box collisions



};



#endif

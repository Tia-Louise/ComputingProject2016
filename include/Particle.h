#ifndef PARTICLE_H__
#define PARTICLE_H__

#include <ngl/Vec3.h>
#include <ngl/Colour.h>
#include <ngl/Camera.h>
#include <ngl/Transformation.h>
#include "Scene.h"

class Emitter;

class Scene;

class Particle
{
public :

  Particle(ngl::Vec3 _pos, //Position of particle
            ngl::Vec3 *_wind,
            Emitter *_parent//The parent(Emitter used to query global values)
           );

  Particle();



  void update();//Method to update the particle position
  void draw();//Method to draw the particle

  inline void reverse(){m_dir=m_dir*-1.0;}
  inline void setHit(){m_hit=true;}
  inline void setNotHit(){m_hit=false;}
  inline bool isHit()const {return m_hit;}
  inline ngl::Vec3 getPos() const {return m_pos;}
  inline ngl::Vec3 getNextPos() const {return m_nextPos;}
  inline GLfloat getRadius() const {return m_radius;}
  inline void setDirection(ngl::Vec3 _d){m_dir=_d;}
  inline ngl::Vec3 getDirection() const { return m_dir;}

  void move();


private :

  ngl::Vec3 m_pos;//Current particle position
  ngl::Vec3 m_origin;//Original particle position
  ngl::Vec3 m_dir;
  bool m_hit;
  GLfloat m_radius;
  ngl::Colour m_colour;//Colour of the particle
  float m_currentLife;//Current life value of the particle
  ngl::Vec3 *m_wind;//Wind Vector
  GLfloat m_gravity;//Gravity Vector

  const Emitter *m_parent;//Pointer to emmiter
  const ngl::Camera *m_camera;

  ngl::Vec3 m_lastPos;//Last position
  ngl::Vec3 m_nextPos;//next position
};


#endif

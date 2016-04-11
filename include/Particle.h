#ifndef PARTICLE_H__
#define PARTICLE_H__

#include <ngl/Vec3.h>
#include <ngl/Colour.h>
#include <ngl/Camera.h>

class Emitter;

class Particle
{
public :

  Particle(
            ngl::Vec3 _pos,//Position of particle
            ngl::Vec3 *_wind,//Wind vector
            Emitter *_parent//The parent(Emitter used to query global values)
           );

  void update();//Method to update the particle position
  void draw();//Method to draw the particle

private :

  ngl::Vec3 m_pos;//Current particle position
  ngl::Vec3 m_origin;//Original particle position
  ngl::Vec3 m_dir;//Direction vector of the particle
  ngl::Colour m_colour;//Colour of the particle
  float m_currentLife;//Current life value of the particle
  GLfloat m_gravity;//Gravity Vector
  ngl::Vec3 *m_wind;//Wind Vector
  const Emitter *m_parent;//Pointer to emmiter
  const ngl::Camera *m_camera;
};


#endif

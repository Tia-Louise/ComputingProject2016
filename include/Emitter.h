#ifndef EMITTER_H__
#define EMITTER_H__
#include <vector>
#include <ngl/Camera.h>
#include <ngl/Vec3.h>
#include <memory>

#include "Particle.h"


class Emitter
{
public :

  Emitter(ngl::Vec3 _pos, int _numParticles, ngl::Vec3 *_wind);//_pos the position of the emitter. _numParticles the number of particles to create
  ~Emitter();

  void addParticle();
  void removeParticle();
  void clearParticles();

  void draw();//Method to draw all the particles.
  void update(); //Method to update each of the particles contained in the system
  inline void setCam(ngl::Camera *_cam){m_cam=_cam;}
  inline ngl::Camera * getCam()const {return m_cam;}
  inline void setShaderName(const std::string &_n){m_shaderName=_n;}
  inline const std::string getShaderName()const {return m_shaderName;}
  inline unsigned int getNumParticles()const {return m_numParticles;}
  inline void setPos(const ngl::Vec3 &_v){m_pos=_v;}
  inline void setGlobalTransform(const ngl::Mat4 &_t){m_globalMouseTX=_t;}
  inline const ngl::Mat4 & getGlobalTransform() const { return m_globalMouseTX;}


private :

  ngl::Vec3 m_pos; //Position of emitter
  int m_numParticles;//Number of particles
  std::vector <Particle> m_particles;//Container of Particles
  ngl::Vec3 *m_wind;//Wind vector
  GLfloat m_gravity;//Gravity Vector
  std::string m_shaderName;//Name of shader to use
  ngl::Camera *m_cam;//Pointer to the camera used for drawing
  ngl::Mat4 m_globalMouseTX;

};


#endif

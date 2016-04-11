#ifndef PARTICLE_FACTORY_H__
#define PARTICLE_FACTORY_H__

#include "Particle.h"


// pre declare the Emitter class as we need this as the parent
class Emitter;

class ParticleFactory
{
  public :


    Particle *CreateParticle(
                              ngl::Vec3 _pos,
                              ngl::Vec3 *_wind,
                              Emitter *_parent
                            );

  private :


};


#endif

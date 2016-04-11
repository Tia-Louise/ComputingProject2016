#include "ParticleFactory.h"



Particle * ParticleFactory::CreateParticle(ngl::Vec3 _pos, //Direction of particle
                                            ngl::Vec3 *_wind, //Wind vector
                                            Emitter *_parent)
{
      return new Particle(_pos,_wind,_parent);
}


#include "Emitter.h"
#include "ParticleFactory.h"
#include <ngl/Random.h>
#include <ngl/Camera.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Emitter::Emitter(ngl::Vec3 _pos, int _numParticles, ngl::Vec3 *_wind )// _pos the position of the emitter. _numParticles the number of particles to create
{
  m_wind=_wind;
  for (int i=0; i< _numParticles; ++i)
  {
    m_particles.push_back(Particle(_pos,m_wind,this));
  }
  m_numParticles=_numParticles;


  ngl::Random *rng=ngl::Random::instance();
  ngl::Colour c;
  c=rng->getRandomColour();//Get a random colour

}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Emitter::addParticle()
{

  ParticleFactory *p = new  ParticleFactory;
  ngl::Random *rng=ngl::Random::instance();

  ngl::Vec3 dir;
  ngl::Colour c;
  dir=rng->getRandomVec3();
  c=rng->getRandomColour();

  delete p;//delete the factory

  if(m_numParticles<400)
  {
    ++m_numParticles;
  }
  else
  {

  }
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void Emitter::removeParticle()
{
  if(m_numParticles>0)//Check if there are any particles in our system
  {
    m_particles.pop_back();//Remove from end of std::vector
    --m_numParticles;//Decremeant the number of particles
  }
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Emitter::~Emitter()
{
  m_particles.clear();
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void Emitter::clearParticles()
{
  // must remember to re-size the std::vector back to 0
  m_particles.clear();
  m_numParticles=0;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void Emitter::draw()//Method to draw all the particles contained in the system
{
  for(int i=0; i<m_numParticles; ++i)
  {
    m_particles[i].draw();
  }
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


void Emitter::update()//Method to update each of the particles contained in the system
{
  for(int i=0; i<m_numParticles; ++i)
  {
    m_particles[i].update();
  }
}


//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------





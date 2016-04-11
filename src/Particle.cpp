#include "Particle.h"
#include <ngl/Camera.h>
#include <ngl/Random.h>
#include <ngl/Transformation.h>
#include <ngl/ShaderLib.h>
#include <ngl/VAOPrimitives.h>
#include "Emitter.h"


Particle::Particle(ngl::Vec3 _pos, ngl::Vec3 *_wind,  Emitter *_parent )//_pos the start position of the particle
{
  m_pos=_pos;
  m_origin=_pos;
  m_wind=_wind;


  ngl::Random *rand=ngl::Random::instance();

  m_colour = rand->getRandomColour();
  m_dir.m_x=rand->randomNumber(5)+0.5;
  m_dir.m_y=rand->randomPositiveNumber(10)+0.5;
  m_dir.m_z=rand->randomNumber(5)+0.5;
  m_currentLife=0.0;
  m_gravity=-9.81;//4.65;
  m_parent=_parent;


}

void Particle::update()//method to update the particle position
{

  m_currentLife+=0.05;
  // use projectile motion equation to calculate the new position
  // x(t)=Ix+Vxt
  // y(t)=Iy+Vxt-1/2gt^2
  // z(t)=Iz+Vzt
  m_pos.m_x=m_origin.m_x+(m_wind->m_x*m_dir.m_x*m_currentLife);
  m_pos.m_y= m_origin.m_y+(m_wind->m_y*m_dir.m_y*m_currentLife)+m_gravity*(m_currentLife*m_currentLife);
  m_pos.m_z=m_origin.m_z+(m_wind->m_z*m_dir.m_z*m_currentLife);

  // if we go below the origin re-set
  if(m_pos.m_y <= m_origin.m_y-0.01)
  {
    m_pos=m_origin;
    m_currentLife=0.0;
    ngl::Random *rand=ngl::Random::instance();
    m_dir.m_x=rand->randomNumber(5)+0.5;
    m_dir.m_y=rand->randomPositiveNumber(10)+0.5;
    m_dir.m_z=rand->randomNumber(5)+0.5;

  }
}

void Particle::draw()//Method to draw particle
{
  // get the VAO instance and draw the built in Sphere
  ngl::VAOPrimitives *prim=ngl::VAOPrimitives::instance();
  ngl::Transformation transform;
  ngl::ShaderLib *shader=ngl::ShaderLib::instance();
  transform.setPosition(m_pos);
  ngl::Mat4 MV;
  ngl::Mat4 MVP;
  ngl::Mat3 normalMatrix;
  ngl::Mat4 M;
  M=transform.getMatrix();
  MV=transform.getMatrix()*m_parent->getCam()->getViewMatrix();
  MVP=MV*m_parent->getCam()->getProjectionMatrix() ;
  normalMatrix=MV;
  normalMatrix.inverse();
  shader->setShaderParamFromMat4("MV",MV);
  shader->setShaderParamFromMat4("MVP",MVP);
  shader->setShaderParamFromMat3("normalMatrix",normalMatrix);
  shader->setShaderParamFromMat4("M",M);
  prim->draw("sphere");

  ngl::Transformation tx;
  tx.setPosition(m_pos);

  shader->use("nglColourShader");
  shader->setUniform("Colour", m_colour);
  shader->setUniform("MVP", tx.getMatrix()*m_camera->getVPMatrix());
  ngl::VAOPrimitives::instance()->draw("sphere");

}


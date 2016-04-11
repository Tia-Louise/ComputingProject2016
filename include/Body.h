//#ifndef BODY_H
//#define BODY_H

//#include <vector>
//#include <iostream>

/////INCLUDING HEADERS
////---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//#include <ngl/Vec2.h>
//#include <stdint.h>
//#include <math.h>


//struct Shape;

//struct Body
//{
//    Body( Shape *shape_, uint32_t);

//  void ApplyForce( const ngl::Vec2& f )
//  {
//    force += f;
//  }

//  void ApplyImpulse( const ngl::Vec2& impulse, const ngl::Vec2& contactVector )
//  {
//    velocity += im * impulse;
//   // angularVelocity += iI * Cross(contactVector, impulse );
//  }

//  void SetStatic( void )
//  {
//    I = 0.0f;
//    iI = 0.0f;
//    m = 0.0f;
//    im = 0.0f;
//  }

//  void SetOrient( ngl::Real radians );

//  ngl::Vec2 position;
//  ngl::Vec2 velocity;

//  ngl::Real angularVelocity;
//  ngl::Real torque;
//  ngl::Real orient; // radians

//   ngl::Vec2 force;

//   float x;
//   float y;

//  // Set by shape
//  ngl::Real I;  // moment of inertia
//  ngl::Real iI; // inverse inertia
//  ngl::Real m;  // mass
//  ngl::Real im; // inverse mass

//  // http://gamedev.tutsplus.com/tutorials/implementation/how-to-create-a-custom-2d-physics-engine-friction-scene-and-jump-table/
//  ngl::Real staticFriction;
//  ngl::Real dynamicFriction;
//  ngl::Real restitution;

//  // Shape interface
//  Shape *shape;

//  // Store a color in RGB format
//  ngl::Real r, g, b;
//};

//#endif

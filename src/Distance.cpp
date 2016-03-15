#include <iostream>
#include <Distance.h>



Distance Distance::minus(Distance b)
{
  Distance a;
  a.X = X - b.X;
  a.Y = Y - b.Y;
  a.Z = Z - b.Z;

  return a;
}

void Distance::disp()
{
  std::cout<<X<<","<<Y<<","<<Z<<","<<std::endl;

}


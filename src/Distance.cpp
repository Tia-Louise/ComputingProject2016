#include <iostream>
#include <Distance.h>


void Distance::setCoords(int x, int y, int z)
{
  x;
  y;
  y;
}

Distance Distance::minus(Distance D)
{
  Distance t;
  t.x = x - D.x;
  t.y = y - D.y;
  t.z = z - D.z;
  return t;
}

void Distance::disp()
{
  std::cout<<x<<" "<<y<<" "<<z<<" "<<std::endl;

}


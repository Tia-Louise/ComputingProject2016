#include <iostream>
#include <Distance.h>

Distance Distance::add(Distance D)
{
  Distance t;
  t.millimeters=millimeters + D.millimeters;
  t.centimeters=0;
  if(t.millimeters>=10.0)
  {
    t.millimeters-=10.0;
    t.centimeters++;
  }
  t.centimeters +=centimeters + D.centimeters;
  return t;
}

void Distance::disp()
{
  std::cout<<centimeters<<" "<<millimeters<<" ";

}

//inches = mm. feet = cm

#ifndef DISTANCE_H_
#define DISTANCE_H_

class Distance //Distance between two particles
{

private:

 int X;
 int Y;
 int Z;


public:

 void setCoords(int x, int y, int z)
 {
   X=x;
   Y=y;
   Z=z;
 }
  Distance minus(Distance b);
  void disp();


};


#endif

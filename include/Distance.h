#ifndef DISTANCE_H_
#define DISTANCE_H_

class Distance //Distance between two particles
{

private:

 int x;
 int y;
 int z;


 public:

  void setCoords(int x, int y, int z);
  Distance minus(Distance);
  void disp();

};


#endif

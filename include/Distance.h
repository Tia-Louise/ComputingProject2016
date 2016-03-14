#ifndef DISTANCE_H_
#define DISTANCE_H_

class Distance
{

private:

 float centimeters;
 int millimeters;

 public:

  void setDist(int mm, float cm)
  {
    centimeters = cm;
    millimeters = mm;
  }
  Distance add(Distance);
  void disp();

};


#endif

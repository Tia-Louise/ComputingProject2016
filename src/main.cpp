#include <iostream>
#include <ctime>
#include <chrono>
#include <thread>

///INCLUDING HEADERS
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Distance.h>
#include <Timer.h>



///MAIN FUNCTION TESTING
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
int main()
{
/// TIMER
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Timer aTimer;
  aTimer.Start();

  for (int i =1; i<11;i++)
  {

    std::cout<<i<<std::endl;
//  std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::this_thread::sleep_for(std::chrono::seconds(1));

  }

  std::cout<< "End\n" <<std::endl;

///DISTANCE
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  Distance p1,p2,p3;
  p1.setCoords(7,8,3); //input coordinates
  p2.setCoords(1,1,1);

  p3=p1.minus(p2);

  std::cout<<"\n Particle 1 Coordinates are: "; p1.disp();
  std::cout<<"\n Particle 2 Coordinates are: "; p2.disp();
  std::cout<<"\n Distance between particle coordinates: "; p3.disp();



  return 0;
}


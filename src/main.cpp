#include <iostream>
#include <Timer.h>
#include <ctime>
#include <sys/time.h>
#include <chrono>
#include <thread>
#include <Distance.h>
#include <math.h>



//int main()
//{
//  Timer aTimer;
//  aTimer.Start();

//  for (int i =1; i<10;i++)
//  {

//    std::cout<<i<<std::endl;
////  std::this_thread::sleep_for(std::chrono::milliseconds(1));
//    std::this_thread::sleep_for(std::chrono::seconds(1));

//  }

//  std::cout<< "End\n" <<std::endl;

//  return 0;
//}

int main()
{
  Distance d1,d2,d3;
  d1.setCoords(0,0,0);
  d2.setCoords(0,0,0);
  d3=d1.minus(d2);

  std::cout<<"\n distance 1 = "; d1.disp();
  std::cout<<"\n distance 2 = "; d2.disp();
  std::cout<<"\n distance 3 = "; d3.disp();

  return 0;
}


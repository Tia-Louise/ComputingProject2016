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
  Distance p1,p2,p3;
  p1.setCoords(7,8,3);
  p2.setCoords(1,1,1);

  p3=p1.minus(p2);

  std::cout<<"\n distance 1 = "; p1.disp();
  std::cout<<"\n distance 2 = "; p2.disp();
  std::cout<<"\n distance 3 = "; p3.disp();



  return 0;
}


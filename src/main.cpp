#include <iostream>
#include <Timer.h>
#include <ctime>
#include <sys/time.h>
using namespace std;


int main()
{
  Timer aTimer;
  aTimer.Start();

  for (int i =1; i<10;i++)
  {

    cout<<i<<endl;
    while(aTimer.Elapsed()<1); //delay between counts -> atm has a 1 second delay between 1 and the rest of numbers... need to have second delay between each number...
//  aTimer.Reset();
  }

  cout<< "End\n" <<endl;

  return 0;
}


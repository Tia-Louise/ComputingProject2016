#include <iostream>
#include <Timer.h>
#include <ctime>
#include <sys/time.h>


Timer::Timer(bool start_immediately)
  : start(0), stop(0), running(false)
{
  if (start_immediately)
  {
    Start(true);
  }
}

void Timer::Start(bool reset)
{
  if (!running)
  {
    if(reset)
    {
      start = std::clock();
    }
    running = true;
  }
}

void Timer::Stop()
{
  if (running)
  {
    stop = std::clock();
    running = false;
  }
}

void sleep_for()
{
  sleep_for();
}



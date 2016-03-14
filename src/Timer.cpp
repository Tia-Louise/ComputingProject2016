#include <iostream>
#include <Timer.h>
#include <ctime>
#include <sys/time.h>
using namespace std;

///TIMER_1
//Timer::Timer()
//  {
//    startedAt = 0;
//    pausedAt = 0;
//    paused = false;
//    started = false;
//  }

//bool Timer::TimerHasStarted()
//  {
//    return started;
//  }

//bool Timer::TimerHasStopped()
//  {
//    return !started;
//  }

//bool Timer::TimerIsPaused()
//  {
//    return paused;
//  }

//bool Timer::TimerIsActive()
//  {
//    return !paused & started;
//  }

//void Timer::PauseTimer()
//  {
//    if( paused || !started)
//      return;
//    paused = true;
//    pausedAt = clock();

//  }

//void Timer::ResumeTimer()
//  {
//    if( !paused)
//      return;

//    paused = false;
//    startedAt +=clock() -pausedAt;
//  }

//void Timer::StopTimer()
//  {
//    started = false;
//  }

//void Timer::StartTimer()
//  {
//    if(started)
//      return;

//    started = true;
//    paused = false;
//    startedAt = clock();
//  }

//void Timer::ResetTimer()
//  {
//    paused = false;
//    startedAt = clock();
//  }

//clock_t Timer::Elapsed()
//  {
//    if( !started)
//      return 0;

//    if( paused)
//      return pausedAt - startedAt;

//    return clock() - startedAt;


//  }


///TIMER_2
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


unsigned long Timer::Elapsed() const
{
//  clock_t ticks = (running ? std::clock() : stop) - start;
//  double seconds = (double)ticks / CLOCKS_PER_SEC;
//  unsigned long milliseconds = seconds * 1000;

//  return milliseconds; /// Should return count time with millisecond delay

  return (double)((running ? std::clock() : stop) - start) / CLOCKS_PER_SEC; //should return time with second delay
}

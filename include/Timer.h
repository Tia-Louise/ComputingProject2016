#ifndef TIMER_H_
#define TIMER_H_

#include <iostream>
#include <ctime>

///TIMER_1
//class Timer
//{
//private:
//  clock_t startedAt;
//  clock_t pausedAt;
//  bool started;
//  bool paused;

//public:
//  Timer();
//  bool TimerHasStarted();
//  bool TimerHasStopped();
//  bool TimerIsPaused();
//  bool TimerIsActive();

//  void PauseTimer();
//  void ResumeTimer();
//  void StopTimer();
//  void StartTimer();
//  void ResetTimer();

//  clock_t start = clock();
//  clock_t Elapsed();
//};

///TIMER_2
class Timer
{
public:
  explicit Timer(bool start_immediately = false);

  void Start(bool reset = false);
  void Stop();


  unsigned long Elapsed() const;

private:
  std::clock_t start, stop;
  bool running;

};

#endif

#ifndef TIMER_H_
#define TIMER_H_

#include <iostream>
#include <ctime>


class Timer
{
private:
  std::clock_t start, stop;
  bool running;

public:
  explicit Timer(bool start_immediately = false);

  void Start(bool reset = false);
  void Stop();
  void sleep_for();

};

#endif


#ifndef PROFILER_H_
#define PROFILER_H_

#include "utils.h"

timespec diff(timespec start, timespec end);
timespec add(timespec t1, timespec t2);
const bool operator<(timespec &t1, timespec &t2);
class Profiler {

private:

        map<string, timespec> timers;
        map<string, timespec> timerPeriods;
        map<string, bool> running;

public:

        void startTimer(string name);
        void pauseTimer(string name);

        void clearTimer(string name);

        double readPeriod(string name);
        bool isRunning(string name);

};

#endif /* PROFILER_H_ */

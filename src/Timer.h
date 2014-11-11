#pragma once

#include <iostream>

namespace one
{
    class Timer
    {
        public:
            Timer(unsigned int intervalMS)
                : interval(intervalMS), elapsedMS(0), nextInterval(intervalMS), started(false)
            {
            }

            void Start() { started = true; }
            void Stop() { started = false; }

            bool IsStarted() { return started; }

            void Update(unsigned int deltaMS)
            {
                if (started)
                {
                    elapsedMS += deltaMS;
                }
            }

            bool IntervalPassed()
            {
                if (elapsedMS >= nextInterval)
                {
                    nextInterval += interval;
                    return true;
                }

                return false;
            }

            void Reset()
            {
                elapsedMS = 0;
                nextInterval = interval;
            }

            // returns the progress of the current interval, from 0 to 2
            float IntervalProgress()
            {
                int currentIntervalMS = elapsedMS % interval;

                return currentIntervalMS / (float) interval;
            }
        private:
            bool started;

            unsigned int interval;
            unsigned int nextInterval;
            unsigned int elapsedMS;
    };
}

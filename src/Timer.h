#pragma once

namespace one
{
    class Timer
    {
        public:
            Timer(unsigned int intervalMS)
                : interval(intervalMS), elapsedMS(0), nextInterval(intervalMS)
            {
            }

            void Update(unsigned int deltaMS)
            {
                elapsedMS += deltaMS;
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
        private:
            unsigned int interval;
            unsigned int nextInterval;
            unsigned int elapsedMS;
    };
}

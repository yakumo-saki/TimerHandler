#pragma once

#include "Arduino.h"

class TimerCall
{
    private:
        typedef void (*TimerCallFunction)();

    public:
        typedef void (*TimerCallStatFunction)(std::vector<TimerCall::TimerCallTask_t> &tasks);

        typedef struct {
            String name;
            TimerCallFunction func;
            TimerCallStatFunction statFunc;
            unsigned long lastExecMills;
            unsigned long nextExecMills;
            unsigned long lastElapsedMills;   // 実行した時間（前回）
            unsigned long totalElapsedMills;  // 実行した時間（合計）
            unsigned long callCount;
            unsigned long interval;
        } TimerCallTask_t;

        void add(TimerCallFunction f, String name, unsigned long interval);
        void setStasticsFunction(TimerCallStatFunction f, unsigned long interval = 5000);
        void start();
        void forceOnce();
        void loop();
        void dump();

    protected:
        unsigned long nowMills;
        //   typedef void (*CallbackFunction)(Button2 &);
        std::vector<TimerCallTask_t> tasks;
        TimerCallStatFunction statTask;

};
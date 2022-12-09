#include "clock.h"
#include <string.h>
#define TIME_SIZE 6
#define START_VALUE 0
#define SECONDS_UNITS 5

struct clock_s {
    bool valid;
    uint16_t ticks_per_second;
    uint16_t ticks_count;
    uint8_t time[TIME_SIZE];
};

static struct clock_s instances;



clock_t ClockCreate(uint16_t ticks_per_second){
    instances.valid = false;
    instances.ticks_count = START_VALUE;
    instances.ticks_per_second = ticks_per_second;
    memset(instances.time, START_VALUE, TIME_SIZE);
    return &instances;
}
bool ClockGetTime(clock_t clock, uint8_t * time, uint8_t size){
    memcpy(time, clock->time, size);
    return clock->valid;
}

void ClockSetupTime(clock_t clock, uint8_t const * const time, uint8_t size){
    memcpy(clock->time, time, size);
    clock->valid = true;
}

void ClockNewTick(clock_t clock){
    clock->ticks_count++;
    if (clock->ticks_count == clock->ticks_per_second){
        clock->ticks_count = START_VALUE;
        clock->time[SECONDS_UNITS]++;
         if(clock->time[SECONDS_UNITS] == 10){
            clock->time[SECONDS_UNITS] = 0;
            clock->time[4]++;
         }
    }
   
    
}
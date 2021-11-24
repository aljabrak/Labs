/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== bigTime.cpp ========
 *  This program is an example of using statically created DSP/BIOS
 *  objects with C++ objects.
 *
 *  In this program, C++ is used to create a real-time clock/calendar. 
 *  The C++ class object, Clock, is driven by a variety
 *  of DSP/BIOS objects: two PRD objects, two TSK objects, and an
 *  IDL object. Each DSP/BIOS object has its own instantiation
 *  of the Clock.  When the PRD, TSK, and IDL functions
 *  execute, they call their clock's tick function, advancing
 *  the connected timer by one second.
 *
 *  Because the functions execute at different rates, the attached
 *  clocks also advance at different rates.  For example, one of the
 *  prd objects, prdClock1, has a period of one second.  When prdClock1
 *  runs, it advances its timer by one second.  This results in an
 *  accurate clock.  On the other hand, idlClock runs with every pass
 *  through the idle loop.  Therefore, the number of seconds passed for
 *  its attached timer indicates the number of passes through the
 *  idle loop.  The more idle time in the program, the faster its 
 *  timer will increment.  See the DSP/BIOS configuration file for
 *  more information on the DSP/BIOS objects.
 *
 *  To view the effects of this program, open the following six
 *  DSP/BIOS Message Logs: trace, idlLog0, prdLog0, prdLog1,
 *  tskLog0, and tskLog1.
 *  
 *  You can experiment with advancing Clock at different rates
 *  by changing the Clock::tick function.
 *
 *  NOTE:  For all Simulators, timer interupt rate is configured to
 *         0.200ms and prdClock1 is set to 10 ticks (0.2ms x 10 = 2ms)
 *         These setting allows the Simulator to update at a reasonable
 *         rate.
 *         
 */

#include <std.h>

#include <log.h>
#include <idl.h>
#include <sem.h>
#include <tsk.h>

#include "bigTimecfg.h"

#include "bigTime.h"

/*
 * Extern "C" block to prevent name mangling
 * of functions called within the Configuration
 * Tool
 */
extern "C" {

/* Wrapper functions to call Clock::tick() */
void clockTask(Clock clock);
void clockPrd(Clock clock);
void clockIdle(void);

} // end extern "C"


/* Global clock objects */
Clock cl0(0, idlLog0);  /* idle loop clock */
Clock cl1(1, prdLog0);  /* periodic clock, period = 1 ms */
Clock cl2(2, prdLog1);  /* periodic clock, period = 1 sec */
Clock cl3(3, tskLog0);  /* task clock */
Clock cl4(4, tskLog1);  /* task clock */


int main()
{
    LOG_printf(&trace, "bigTime started.");                                     
}


/*
 * Wrapper function for TSK objects calling
 * Clock::tick()
 */
void clockTask(Clock clock)
{   
    int count = 0;
    if (clock.getId() == 3) {
        while(1) {             // task id = 3
            SEM_pend(&sem0, SYS_FOREVER);
                clock.tick();
                if(count == 50) {
                TSK_sleep(25);
                count = 0;
            } 
            count++;
            SEM_post(&sem1);
        }
    }
    else {
        while(1) {             // task id = 4
            SEM_pend(&sem1, SYS_FOREVER);
            if(count == 50) {
                TSK_sleep(25);
                count = 0;
            }   
            clock.tick();
            count++;
            SEM_post(&sem0);
        }
    }
}

 
/*
 * Wrapper function for PRD objects calling
 * Clock::tick()
 */
void clockPrd(Clock clock)
{
    clock.tick();
    return;
} 


/*
 * Wrapper function for IDL objects calling
 * Clock::tick()
 */
void clockIdle(void)
{ 
    cl0.tick();
    return;
} 


/*
 * Clock methods
 */
Clock::Clock(int newId, LOG_Obj &newLog)
{  
    id = newId;
    ticks = 0;
    microsecond = 0; 
    millisecond = 0;
    second = 0;
    minute = 0; 
    hour = 0;
    day = 1;
    month = 1;
    year = 0;
    century = 0;
    millenium = 0;
    clockLog = &newLog; 
}

Clock::~Clock()
{
}

void Clock::tick()
{
    ticks++;
#ifdef _28_
    LOG_printf(clockLog, "second: %d, minute: %d", (Arg)second, (Arg)minute);
    LOG_printf(clockLog, "hour: %d:", (Arg)hour);
    LOG_printf(clockLog, "%s %d", months[month-1], (Arg)day);
    LOG_printf(clockLog, "year: %d, century: %d\n", (Arg)year, (Arg)century);
#else
    LOG_printf(clockLog, "second: %d, minute: %d", second, minute);
    LOG_printf(clockLog, "hour: %d:", hour);
    LOG_printf(clockLog, "%s %d", months[month-1], day);
    LOG_printf(clockLog, "year: %d, century: %d\n", year, century);
#endif
    /*
     * Change selected function to alter clock rate
     */ 
//  setMicrosecond();
//  setMillisecond();
    setSecond(); 
//  setMinute();
//  setDay(); 
    return;
}

void Clock::setMicrosecond()
{
    if (microsecond >= 999) {
        setMillisecond(); 
        microsecond = 0;
    }
    else {
        microsecond++;
    }
        
    return;
}
 
void Clock::setMillisecond()
{ 
    if (millisecond >= 999) {
        setSecond();
        millisecond = 0;
    }
    else {
        millisecond++;
    }

    return;
}

void Clock::setSecond()
{
    if (second == 59) {
        setMinute(); 
        second = 0;
    }
    else {
        second++;
    }

    return;
}

void Clock::setMinute()
{
    if (minute == 59) {
        setHour();
        minute = 0;
    }
    else {
        minute++;
    }

    return;
}

void Clock::setHour()
{
    if (hour == 23) {
        setDay();
        hour = 0;
    }
    else {
        hour++;
    }

    return;
}

void Clock::setDay()
{ 
    bool thirtydays = false;
    bool feb = false;
    bool leap = false;

    if (month == 4 || month == 6 || month == 9 || month == 11) {
        // April, June, September, November.
        thirtydays = true;
    }

    if (month == 2) {  // test for February
        feb = true;
    }

    /*
     * A year is a leap year if it is divisible by 4, but not by 100.
     *
     * If a year is divisible by 4 and by 100, it is a leap year only
     * if it is also divisible by 400.
     */
    if ((year%4 == 0 && year%100 != 0) || (year%4 == 0 && year%100 == 0 && year%400 == 0)) {
        leap = true; 
    }

    if ((day == 28) && (feb) && (!leap)) {
        setMonth();
        day = 1;
    }
    else if ((day == 29) && (feb) && (leap)) {
        setMonth();
        day = 1;
    }
    else if ((day == 30) && (thirtydays == true)) {
        setMonth();
        day = 1;
    }
    else if ((day == 31) && (thirtydays == false)) { 
        setMonth();
        day = 1;
    }
    else {
        day++;
    }

    return;
}

void Clock::setMonth()
{
    if (month >= 12) {
        setYear();
        month = 1;
    }
    else {
        month++;
    }

    return;
}

void Clock::setYear()
{ 
    year++;
    if ((year%100) == 0) {
        setCentury();
    }

    return;
}

void Clock::setCentury()
{ 
    century++;
    if ((century%1000) == 0) {
        setMillenium();
    }

    return;
}

void Clock::setMillenium()
{
    millenium++; 

    return;
}

long Clock::getTicks()
{
    return ticks;
}

int Clock::getId()
{
    return id;
}

int Clock::getMicrosecond()
{
    return microsecond;
}

int Clock::getMillisecond()
{
    return millisecond;
}

int Clock::getSecond()
{
    return second;
}

int Clock::getMinute()
{
    return minute;
}

int Clock::getHour()
{
    return hour;
}

int Clock::getDay()
{
    return day;
}

int Clock::getMonth()
{
    return month;
}

int Clock::getYear()
{
    return year;
}

int Clock::getCentury()
{
    return century;
}

int Clock::getMillenium()
{
    return millenium;
}


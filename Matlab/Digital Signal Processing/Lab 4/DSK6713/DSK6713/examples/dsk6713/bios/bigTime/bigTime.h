/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
class Clock {
	private:
		 // data
		int id;
		double ticks;
		int microsecond; 
		int millisecond;
		int second;
		int minute;      
		int hour;
		int day;
		int month;
		int year;
		int century;
		int millenium;
		LOG_Obj* clockLog;     
				
	public:
	    // methods         
		Clock(int newId, LOG_Obj &newLog);  // Constructor
		~Clock();                           // Destructor		                           
		void tick();
		long getTicks();
		int getId();
		int getMicrosecond();
		int getMillisecond();
		int getSecond();
		int getMinute();
		int getHour();
		int getDay();
		int getMonth();
		int getYear();
		int getCentury();
		int getMillenium();
        void setMicrosecond();		
        void setMillisecond();
		void setSecond();		
		void setMinute();
		void setHour(); 
		void setDay();
		void setMonth();
		void setYear();
		void setCentury();
		void setMillenium(); 
};

String months[12] = { "January", "February", "March",
                      "April",   "May",      "June",
                      "July",    "August",   "September",
                      "October", "November", "December" };
                                         

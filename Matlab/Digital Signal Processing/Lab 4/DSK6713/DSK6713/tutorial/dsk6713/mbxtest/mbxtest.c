/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== mbxtest.c ========
 *  Use a MBX mailbox to send messages from multiple writer() 
 *  tasks to a single reader() task.
 *  The mailbox, reader task, and three writer tasks are created by the
 *  Configuration Tool.
 *
 *  This example is similar to semtest.c.  The major differences 
 *    are:
 *    - MBX is used in place of QUE and SEM.
 *    - the 'elem' field is removed from MsgObj.
 *    - reader() task is *not* higher priority than writer task.
 *    - reader() looks at return value from MBX_pend() for timeout
 */
 
#include <std.h>

#include <log.h>
#include <mbx.h>
#include <tsk.h>

#include "mbxtestcfg.h"


#define NUMMSGS         3       /* number of messages */

#define TIMEOUT         10

typedef struct MsgObj {
    Int         id;             /* writer task id */
    Char        val;            /* message value */
} MsgObj, *Msg;


Void reader(Void);
Void writer(Arg id_arg);

/*
 *  ======== main ========
 */
Void main()
{
    /* Does nothing */
}

/*
 *  ======== reader ========
 */
Void reader(Void)
{
    MsgObj      msg;
    Int         i;

    for (i=0; ;i++) {

        /* wait for mailbox to be posted by writer() */
        if (MBX_pend(&mbx, &msg, TIMEOUT) == 0) {
            LOG_printf(&trace, "timeout expired for MBX_pend()");
            break;
        }

        /* print value */
#ifdef _28_
        LOG_printf(&trace, "read '%c' from (%d).", (Arg)msg.val, (Arg)msg.id);
#else
        LOG_printf(&trace, "read '%c' from (%d).", msg.val, msg.id);
#endif
    }
    LOG_printf(&trace, "reader done.");
}

/*
 *  ======== writer ========
 */
Void writer(Arg id_arg)
{
    MsgObj      msg;
    Int         i;
    Int id =    ArgToInt (id_arg);

    for (i=0; i < NUMMSGS; i++) {
        /* fill in value */
        msg.id = id;
        msg.val = i % NUMMSGS + (Int)('a');

        /* enqueue message */
        MBX_post(&mbx, &msg, TIMEOUT);
       
#ifdef _28_
        LOG_printf(&trace, "(%d) writing '%c' ...", (Arg)id, (Arg)msg.val);
#else
        LOG_printf(&trace, "(%d) writing '%c' ...", id, (Int)msg.val);
#endif

        /* what happens if you call TSK_yield() here? */
        /* TSK_yield(); */
    }
#ifdef _28_    
    LOG_printf(&trace, "writer (%d) done.", (Arg)id);
#else
    LOG_printf(&trace, "writer (%d) done.", id);
#endif
}


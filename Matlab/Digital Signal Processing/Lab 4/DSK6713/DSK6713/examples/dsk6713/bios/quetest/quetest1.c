/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== quetest1.c ========
 *  Use a QUE queue to send messages from a writer() to a reader().
 *
 *  The queue is created by the Config tool.
 *  In this example, we preallocate a pool of MsgObj's and keep them on
 *  a 'free' queue.
 *
 *  A queue can hold an arbitrary number of messages or elements.
 *  Each message must, however, be a structure with a QUE_Elem as
 *  its first field.
 *
 *  Unlike a real world situation, in this example, no task is ever
 *  waiting for I/O from a real device. If the writer tasks were getting
 *  data from a device and sending it to the reader, they would block
 *  waiting for input from the device (assuming the data rate of the
 *  device was not too fast), allowing the idle task to run and send
 *  information to the host.  In order to create some idle time in this
 *  example, we put a TSK_sleep() in main().
 */

#include <std.h>

#include <log.h>
#include <mem.h>
#include <que.h>
#include <sys.h>
#include <tsk.h>

#include "quetest1cfg.h"

#define NUMMSGS     5      /* number of messages */

typedef struct MsgObj {
    QUE_Elem    elem;      /* first field for QUE */
    Char        val;       /* message value */
} MsgObj, *Msg;


Void reader(Void);
Void writer(Void);

/*
 *  ======== main ========
 */
Void main()
{
    LOG_printf(&trace, "quetest1 example started.\n");
}

/*
 *  ======== initTask ========
 */
Void initTask()
{
    Int         i;
    MsgObj      *msg;


    msg = (MsgObj *)MEM_alloc(0, NUMMSGS * sizeof(MsgObj), 0);
    if (msg == MEM_ILLEGAL) {
        SYS_abort("Memory allocation failed!\n");
    }

    /* Put all messages on freequeue */
    for (i = 0; i < NUMMSGS; msg++, i++) {
        QUE_put(&freequeue, msg); 
    }
}

/*
 *  ======== task ========
 */
Void task() 
{
    /*
     *  The writer() must be called before reader() to ensure that the
     *  queue is non-empty for the reader.
     */
    for (;;) {
        writer();
        reader();

        /* Generate some idle time */
        TSK_sleep(5);
    }
}

/*
 *  ======== reader ========
 */
Void reader()
{
    Msg         msg;
    Int         i;

    for (i = 0; i < NUMMSGS; i++) {

        /* The queue should never be empty */
        if (QUE_empty(&queue)) {
            SYS_abort("queue error\n");
        }

        /* dequeue message */
        msg = QUE_get(&queue);
        
        /* print value */
        LOG_printf(&trace, "read '%c'.", msg->val);

        /* free msg */
        QUE_put(&freequeue, msg);
    }
}

/*
 *  ======== writer ========
 */
Void writer()
{
    Msg         msg;
    Int         i;

    for (i = 0; i < NUMMSGS; i++) {
        msg = QUE_get(&freequeue);

        /* fill in value */
        msg->val = (i & 0xf) + 'a';

        LOG_printf(&trace, "writing '%c' ...", msg->val);

        /* enqueue message */
        QUE_put(&queue, msg);
    }
}

/*
 *  Copyright 2003 by Texas Instruments Incorporated.
 *  All rights reserved. Property of Texas Instruments Incorporated.
 *  Restricted rights to use, duplicate or disclose this code are
 *  granted through contract.
 *  
 */
/* "@(#) DSP/BIOS 4.90.270 01-08-04 (bios,dsk6713-c04)" */
/*
 *  ======== quetest.c ========
 *  Use a QUE queue to send messages from a writer() to a reader().
 *
 *  The queue is created by the Configuration Tool.
 *  For simplicity, we use MEM_alloc() and MEM_free() to manage 
 *  the MsgObj structures.  It would be way more efficient to 
 *  preallocate a pool of MsgObj's and keep them on a 'free' 
 *  queue. Using the Config tool, create 'freeQueue'.  Then in main(),
 *  allocate the MsgObj's with MEM_alloc() and add them to 'freeQueue'
 *  with QUE_put().   
 *  You can then replace the MEM_alloc() calls with 
 *  QUE_get(freeQueue) and MEM_free() with QUE_put(freeQueue, msg).
 *
 *  A queue can hold an arbitrary number of messages or elements.
 *  Each message must, however, be a structure with a QUE_Elem as
 *  its first field.
 */

#include <std.h>

#include <log.h>
#include <mem.h>
#include <que.h>
#include <sys.h>

#include "quetestcfg.h"

#define NUMMSGS     5      /* number of messages */

typedef struct MsgObj {
    QUE_Elem    elem;      /* first field for QUE */
    Char        val;       /* message value */
} MsgObj, *Msg;


Void reader();
Void writer();

/*
 *  ======== main ========
 */
Void main()
{
    /*
     *  The writer() must be called before reader() to ensure that the
     *  queue is non-empty for the reader.
     */
    writer();
    reader();
}

/*
 *  ======== reader ========
 */
Void reader()
{
    Msg         msg;
    Int         i;

    for (i=0; i < NUMMSGS; i++) {

        /* The queue should never be empty */
        if (QUE_empty(&queue)) {
            SYS_abort("queue error\n");
        }

        /* dequeue message */
        msg = QUE_get(&queue);
        
        /* print value */
#ifdef _28_
        LOG_printf(&trace, "read '%c'.", (Arg)msg->val);
#else
        LOG_printf(&trace, "read '%c'.", msg->val);
#endif

        /* free msg */
        MEM_free(0, msg, sizeof(MsgObj));
    }
}

/*
 *  ======== writer ========
 */
Void writer()
{
    Msg         msg;
    Int         i;

    for (i=0; i < NUMMSGS; i++) {

        /* allocate msg */
        msg = MEM_alloc(0, sizeof(MsgObj), 0);
        if (msg == MEM_ILLEGAL) {
            SYS_abort("Memory allocation failed!\n");
        }

        /* fill in value */
        msg->val = i + 'a';

#ifdef  _28_
        LOG_printf(&trace, "writing '%c' ...",(Arg) msg->val);
#else
        LOG_printf(&trace, "writing '%c' ...", msg->val);
#endif

        /* enqueue message */
        QUE_put(&queue, msg);
    }
}

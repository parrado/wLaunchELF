/*********************************************************************
 * Copyright (C) 2003 Tord Lindstrom (pukko@home.se)
 * This file is subject to the terms and conditions of the PS2Link License.
 * See the file LICENSE in the main directory of this distribution for more
 * details.
 */

#include <stdio.h>
#include <sysclib.h>
#include <loadcore.h>
#include <intrman.h>
#include <types.h>
#include <sifrpc.h>
#include <cdvdman.h>

// Entry points
extern int fsysMount(void);
////////////////////////////////////////////////////////////////////////
// main
//   start threads & init rpc & filesys
int
_start( int argc, char **argv)
{
    FlushDcache();
    CpuEnableIntr(0);

    sceCdInit(1);
    sceCdStop();

    SifInitRpc(0);

    fsysMount();
    return 0;
}


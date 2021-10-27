// SPDX-FileCopyrightText: Copyright (c) 2021 Electronics and Telecommunications Research Institute
// SPDX-License-Identifier: GPL-2.0
#include <linux/module.h>
#include <linux/memory.h>
#include <linux/mutex.h>
#include <linux/mmzone.h>

extern enum dcpmm_states dcpmm_state;

unsigned long long dcpmm[12]= {
        0x3040000000UL,0x6f40000000UL,0xae40000000UL,0xed40000000UL,
        0x12c40000000UL,0x16b40000000UL,0x1da40000000UL,0x21940000000UL,
        0x25840000000UL,0x29740000000UL,0x2d640000000UL,0x31540000000UL
};

static int __init add_dcpmm(void)
{
	int nid, i, flag=false;
	int rc;
	u64 start, size=0x3f00000000UL;;
	
	for (i=0;i<12;i++)
	{
		start = dcpmm[i];
		nid = i+4;
		rc = add_memory(nid, start, size);
		if (!rc) 
			flag=true;
	}
	dcpmm_state = flag ? ADDON:FAILED;

	return 0;
}

late_initcall(add_dcpmm);

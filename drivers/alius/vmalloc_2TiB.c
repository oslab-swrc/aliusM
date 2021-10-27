// SPDX-FileCopyrightText: Copyright (c) 2021 Electronics and Telecommunications Research Institute
// SPDX-License-Identifier: GPL-2.0
#include<linux/init.h>
#include<linux/module.h>
#include<linux/slab.h>
#include<linux/mm.h>
#include<linux/vmalloc.h>

char *buf;

static int kmalloc_init(void)
{

	unsigned long gib = 0x40000000UL;
	unsigned long mul = 2048UL;
	unsigned long size;

	size=gib*mul;

	buf=vmalloc(size);
	if (!buf)
	{
		printk(KERN_INFO "vmalloc(%#lx) error\n",size);
		return 0;
	}
	else
		printk(KERN_INFO "vmalloc(%#lx) success\n",size);
	return 0;
}
static void kmalloc_exit(void)
{
	vfree(buf);
	printk(KERN_INFO "Memory freed\n");
}
module_init(kmalloc_init);
module_exit(kmalloc_exit);

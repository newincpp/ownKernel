/* Copyright (C) 1999, 2001  Free Software Foundation, Inc.
   2 
   3    This program is free software; you can redistribute it and/or modify
   4    it under the terms of the GNU General Public License as published by
   5    the Free Software Foundation; either version 2 of the License, or
   6    (at your option) any later version.
   7 
   8    This program is distributed in the hope that it will be useful,
   9    but WITHOUT ANY WARRANTY; without even the implied warranty of
   10    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   11    GNU General Public License for more details.
   12 
   13    You should have received a copy of the GNU General Public License
   14    along with this program; if not, write to the Free Software
   15    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

#ifndef MULTIBOOT_H_
#define MULTIBOOT_H_

#ifdef __cplusplus
extern "C" {
#endif

#define MULTIBOOT_HEADER_MAGIC 0x1BADB002 
#define MULTIBOOT_HEADER_FLAGS 0x00010003 
#define MULTIBOOT_HEADER_CHECKSUM (-(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)) 
#define MULTIBOOT_BOOTLOADER_MAGIC 0x2BADB002 
    typedef struct multiboot_header {
	unsigned long magic;         
	unsigned long flags;         
	unsigned long checksum;      
	unsigned long header_addr;   
	unsigned long load_addr;     
	unsigned long load_end_addr; 
	unsigned long bss_end_addr;  
	unsigned long entry_addr;    
    } multiboot_header_t;

    typedef struct aout_symbol_table {
	unsigned long tabsize;
	unsigned long strsize;
	unsigned long addr;
	unsigned long reserved;
    } aout_symbol_table_t;

    typedef struct elf_section_header_table {
	unsigned long num;
	unsigned long size;
	unsigned long addr;
	unsigned long shndx;
    } elf_section_header_table_t;

    typedef struct multiboot_info {
	unsigned long flags;
	unsigned long mem_lower;
	unsigned long mem_upper;
	unsigned long boot_device;
	unsigned long cmdline;
	unsigned long mods_count;
	unsigned long mods_addr;
	union {
	    aout_symbol_table_t aout_sym;
	    elf_section_header_table_t elf_sec;
	} u;
	unsigned long mmap_length;
	unsigned long mmap_addr;
    } multiboot_info_t;

    typedef struct module {
	unsigned long mod_start;
	unsigned long mod_end;
	unsigned long string;
	unsigned long reserved;
    } module_t;

    typedef struct memory_map {
	unsigned long size;
	unsigned long base_addr_low;
	unsigned long base_addr_high;
	unsigned long length_low;
	unsigned long length_high;
	unsigned long type;
    } memory_map_t;

    enum multiboot_info_flags {
	MULTIBOOT_INFO_FLAGS_MEM     = 0x01,
	MULTIBOOT_INFO_FLAGS_BOOT    = 0x02,
	MULTIBOOT_INFO_FLAGS_CMDLINE = 0x04,
	MULTIBOOT_INFO_FLAGS_MODS    = 0x08,
	MULTIBOOT_INFO_FLAGS_SYMS1   = 0x10,
	MULTIBOOT_INFO_FLAGS_SYMS2   = 0x20,
	MULTIBOOT_INFO_FLAGS_MMAP    = 0x40,
    };

#ifdef __cplusplus
}
#endif

#endif /* MULTIBOOT_H_ */

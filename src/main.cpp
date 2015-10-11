#include "vga.hh"
#include "multiboot.h"

unsigned int strlen(const char* str) {
    unsigned int i = 0;
    while (str[i]) {
	++i;
    }
    return i;
}

void kmain(unsigned int magic, struct multiboot_info* info) {
    (void)magic;
    (void)info;
    VGA display;
    display.setBg(COLOR_RED);
    display.resetBg();
    display.printk("0\n");
    display.printk("1\n");
    display.printk("2\n");
    display.printk("3\n");
    display.printk("4\n");
    display.printk("5\n");
    display.printk("6\n");
    display.printk("7\n");
    display.printk("8\n");
    display.printk("9\n");
    display.printk("10\n");
    display.printk("11\n");
    display.printk("12\n");
    display.printk("13\n");
    display.printk("14\n");
    display.printk("15\n");
    display.printk("16\n");
    display.printk("17\n");
    display.printk("18\n");
    display.printk("19\n");
    display.printk("20\n");
    display.printk("21\n");
    display.printk("22\n");
    display.printk("23\n");
    display.printk("24\n");
    display.printk("25\n");
    display.printk("26\n");
    display.resetBg();
    display.printk("yay 27\n");
}

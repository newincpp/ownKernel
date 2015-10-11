#include "uart.hh"
#include "vga.hh"
#include "multiboot.h"

extern "C" {
    void printk(const char* message_) { // boring and not flexible but mandatory =/
	UART com;
	VGA v;
	v.put(message_, COLOR_WHITE);
	com.send(message_);
    }
}

void kmain(unsigned int magic, struct multiboot_info* info) {
    (void)magic;
    (void)info;
    VGA display;
    display.setBg(COLOR_RED);
    display.resetBg();
    display.print("welcome on bruOS\n");

    printk("lol\n");
    printk("yay\n");
}

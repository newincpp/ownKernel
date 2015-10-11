#include "uart.hh"

UART::UART(unsigned short port_) : _port(port_) {
}

void UART::send(const char* message_) {
    for (unsigned int i = 0; message_[i]; ++i) {
	asm volatile("outb %0, %1\n\t"
		: /* No output */
		: "a" (message_[i]), "d" (_port));
    }
}

void UART::recieve(char* buffer_, unsigned int buffsize) {
    for (unsigned int i = 0; i < buffsize ; ++i) {
	asm volatile("inb %1, %0\n\t"
		: "=a" (buffer_[i])
		: "d" (_port));
    }
}

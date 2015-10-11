#ifndef UART_H_
# define UART_H_

#define COM1 0x3F8
#define COM2 0x2F8
#define COM3 0x3E8
#define COM4 0x2E8

class UART {
    private:
	unsigned short _port;
    public:
	UART(unsigned short = COM1);
	void send(const char*);
	void recieve(char*, unsigned int);
};

#endif /* !UART_H_ */

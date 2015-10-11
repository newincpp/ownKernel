#ifndef UART_H_
# define UART_H_

class UART {
    private:
	unsigned short _port;
    public:
	UART();
	void send(const char*);
	void recieve(char*, unsigned int);
};

#endif /* !UART_H_ */

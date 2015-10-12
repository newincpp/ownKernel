#ifndef VGA_H_
# define VGA_H_

#include "VGAInfos.h"

#define SIZE_COL 80
#define SIZE_LINE 25

class VGA {
    public:
	class Cursor {
	    private:
		unsigned short _x;
		unsigned short _y;
	    public:
		Cursor();
		Cursor(Cursor&);
		unsigned short& getX();
		unsigned short& getY();
		unsigned int index()const;
		inline void carriageReturn() {
		    _y++;
		    _x = 0;
		}
	};
    private:
	Cursor _cursor;
	char* const _video_mem;
	ubyte _backgroudColor;
	ubyte _genColor(ubyte, ubyte)const;
    public:
	VGA();
	void operator<<(const char*);
	void put(const char*, ubyte);
	void setBg(ubyte newBg_) {
	    _backgroudColor = newBg_;
	}
	void resetBg();
	void autoScroll();
	void print(const char*);
	Cursor& getCursor();
	void clear(ubyte);
	inline void clear() {
	    clear(_backgroudColor);
	}
};

extern "C" {
    void printk(const char* message);
}

#endif /* !VGA_H_ */

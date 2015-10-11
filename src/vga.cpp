#include "vga.hh"

VGA::Cursor::Cursor() : _x(0), _y(0) {
    asm volatile("outb %0, %1\n\t"
	    : /* No output */
	    : "a" ((unsigned char)0x3D4), "d" ((unsigned short)0x0F));
    asm volatile("outb %0, %1\n\t"
	    : /* No output */
	    : "a" ((unsigned char)0x3D4), "d" ((unsigned short)0x0E));
}

VGA::Cursor::Cursor(Cursor& o_) : _x(o_._x), _y(o_._y) {
}

unsigned short& VGA::Cursor::getX() {
    if (_x >= SIZE_COL)
	_x = SIZE_COL;
    return _x;
}

unsigned short& VGA::Cursor::getY() {
    if (_y >= SIZE_LINE)
	_y = SIZE_LINE;
    return _y;
}

unsigned int VGA::Cursor::index() const {
    return (_y * SIZE_COL) + _x;
}

ubyte VGA::_genColor(ubyte fg_, ubyte bg_) const {
    return fg_ | bg_ << 4;
}

void VGA::put(const char* str_, ubyte color_) {
    unsigned int i = 0;
    while (str_[i]) {
	if (str_[i] == '\n') {
	    _cursor.carriageReturn();
		autoScroll();
	} else {
	    _video_mem[_cursor.index() * 2] = str_[i];
	    _video_mem[(_cursor.index() * 2) + 1] = _genColor(color_, _backgroudColor);
	    _cursor.getX()++;
	    if (_cursor.getX() == SIZE_COL) {
		_cursor.carriageReturn();
		    autoScroll();
	    }
	}
	++i;
    }
}

void VGA::autoScroll() {
    if (_cursor.getY() != SIZE_LINE) {
	return;
    }
    char* const source = _video_mem + (SIZE_COL * 2);
    char* const destination = _video_mem;
    unsigned int i = 0;
    while (i < (SIZE_COL * SIZE_LINE * 2)) {
	destination[i] = source[i];
        ++i;
    }
}

void VGA::clear(ubyte color_) {
    for (unsigned int i = 1; i < (SIZE_LINE* SIZE_COL * 2) ; i += 2) {
	_video_mem[i] = _genColor(color_, color_);
    }
    _cursor.getX() = 0;
    _cursor.getY() = 0;
}

void VGA::resetBg() {
    unsigned int i = 1;
#pragma pack(1)
    struct _color_ {
	int fg : 4;
	int bg : 4;
    };
#pragma pack(0)
    while (i <= (SIZE_COL * SIZE_LINE * 2)) {
    ((_color_*)_video_mem)[i].bg = _backgroudColor;
	i += 2;
    }
}

VGA::Cursor& VGA::getCursor() {
    return _cursor;
}

void VGA::print(const char* message_) {
    put(message_, COLOR_WHITE);
}

VGA::VGA() : _video_mem((char*)0xb8000), _backgroudColor(COLOR_BLACK) {
    for (unsigned int i = 0; i < (SIZE_LINE* SIZE_COL * 2) ; ++i) {
	_video_mem[i] = 0;
    }
}


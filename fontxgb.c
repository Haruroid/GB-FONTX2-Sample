#include <gb/gb.h>
#include <stdint.h>
#include <stdlib.h>
#include <gb/drawing.h>
#include "HR_FONTX2.h"
#include <gbdk/incbin.h>

INCBIN(HANF, "SHNHN12.FNT")
INCBIN_EXTERN(HANF)

void lcdwrite(uint16_t x, uint16_t y, uint16_t col) {
	plot_point(x, y);
}

void readH(uint16_t off,uint16_t size,uint8_t* buf){
	memcpy(buf,((uint8_t*)HANF)+off,size);
}

void main(void)
{
    color(BLACK,WHITE,SOLID);
	if(!HR_FONTX2_init(readH,NULL,lcdwrite))
		circle(140,40,15,M_FILL);

	HR_FONTX2_writeString("HELLO from HR_FONTX2",0,0,0);
}

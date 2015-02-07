//ShiftDevice.h - class library for all robot devices controlled by the shift register
#ifndef ShiftDevice_h
#define ShiftDevice_h

class ShiftDevice
{
public:
	ShiftDevice();
	~ShiftDevice();
	unsigned char getActiveByte();
	unsigned char getMask();
protected:/* data */
	unsigned char _activeByte;
	unsigned char _controlByte;
	unsigned char _mask;	
};

#endif
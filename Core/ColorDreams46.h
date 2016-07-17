#pragma once
#include "stdafx.h"
#include "BaseMapper.h"

class ColorDreams46 : public BaseMapper
{
private:
	uint8_t _regs[2];

protected:
	virtual uint16_t RegisterStartAddress() { return 0x6000; }
	virtual uint16_t RegisterEndAddress() { return 0xFFFF; }
	virtual uint16_t GetPRGPageSize() { return 0x8000; }
	virtual uint16_t GetCHRPageSize() { return 0x2000; }

	void InitMapper()
	{
		WriteRegister(0x6000, 0);
		WriteRegister(0x8000, 0);
	}

	virtual void Reset(bool softReset)
	{
		WriteRegister(0x6000, 0);
		WriteRegister(0x8000, 0);
	}

	void UpdateState()
	{
		SelectPRGPage(0, ((_regs[0] & 0x0F) << 1) | (_regs[1] & 0x01));
		SelectCHRPage(0, ((_regs[0] & 0xF0) >> 1) | ((_regs[1] & 0x70) >> 4));
	}

	void WriteRegister(uint16_t addr, uint8_t value)
	{
		if(addr < 0x8000) {
			_regs[0] = value;
		} else {
			_regs[1] = value;
		}
		UpdateState();
	}
};

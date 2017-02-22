/*
 * Copyright (C) 2017  Andrey V. Skvortsov <starling13@mail.ru>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <util/crc16.h>
#include <assert.h>

class ExtMem
{
public:

	enum Type_t : uint8_t
	{
		MEGA32_SHIELD
	};

	void
	begin(Type_t type)
	{
		switch (type) {
		case MEGA32_SHIELD:
			XMCRA = 0x0;
			XMCRA |= 1ul << 7; // Switch ext mem iface on
			XMCRB = 0;
			//XMCRB |= 1; // 7-bit address space
			_startAddress = (void*) (0x2200);
			_memSize = 1ull << 15;
			break;
		default:
			Serial.println("Invalid external memory type");
		}
	}

	size_t
	memSize() const
	{
		return (_memSize);
	}

	void *
	begin()
	{
		return (_startAddress);
	}

	void *
	end()
	{
		return ((void*) (intptr_t(_startAddress) + _memSize));
	}

private:
	void *_startAddress;
	size_t _memSize;
};

static ExtMem extmem;

void
setup()
{
	Serial.begin(19200);
	pinMode(LED_BUILTIN, OUTPUT);
	extmem.begin(ExtMem::MEGA32_SHIELD);

	Serial.println("Starting external memory test?(Y/N)");
	while (Serial.available() <= 0);
	char c = Serial.read();
	if (c != 'Y' && c != 'y')
		assert(0);
	uint8_t *mem = (uint8_t*) extmem.begin();
	Serial.print("Filling with random data "), Serial.print(extmem.memSize()), Serial.println(" bytes...");
	uint16_t crc = 0;
	for (size_t i = 0; i < extmem.memSize(); ++i) {
		mem[i] = random();
		crc = _crc16_update(crc, mem[i]);
		if ((i % 128) == 0 && i > 0)
			Serial.print('.');
		if ((i % 4096) == 0 && i > 0)
			Serial.println();
	}
	Serial.println(), Serial.print("done, CRC16 hash: "), Serial.println(crc, HEX);

	Serial.println("Reading data");
	uint16_t crc2 = 0;
	for (size_t i = 0; i < extmem.memSize(); ++i) {
		crc2 = _crc16_update(crc2, mem[i]);
		if ((i % 128) == 0 && i > 0)
			Serial.print('.');
		if ((i % 4096) == 0 && i > 0)
			Serial.println();
	}
	Serial.println();
	if (crc == crc2)
		Serial.print("TEST PASSED! ");
	else
		Serial.print("TEST FAILED! ");
	Serial.print("CRC16 hash: "), Serial.println(crc2, HEX);
}

void
loop()
{

}

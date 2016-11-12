#include "cps_mosprotocol.hpp"

#include "helper.hpp"

using namespace cps;

bool
MOSProtocol::checkHeader(const header_t &header)
{
	if ((header._data.soh == uint8_t(Codes::SOH)) &&
	    (header._data.stx == uint8_t(Codes::STX)) &&
	    (header._data.invLen == ~header._data.len) &&
	    (header._data.headerSum == header._data.soh + header._data.flags +
	        header._data.id + (header._data.len >> 8) + (header._data.len & 0x0F)
	      + (header._data.invLen >> 8) + (header._data.invLen &0x0F))) {
		return (true);
	} else {
		return (false);
	}
}

void
MOSProtocol::prepareHeader(header_t &header,
    length_t len, uint16_t id, Flags_t flags)
{
	header._data.soh = uint8_t(Codes::SOH);
	header._data.flags = uint8_t(flags);
	header._data.id = id;
	header._data.len = len;
	header._data.invLen = ~len;
	header._data.stx = uint8_t(Codes::STX);
	header._data.headerSum = header._data.soh + header._data.flags +
	        header._data.id + (header._data.len >> 8) + (header._data.len & 0x0F)
	      + (header._data.invLen >> 8) + (header._data.invLen &0x0F);
}

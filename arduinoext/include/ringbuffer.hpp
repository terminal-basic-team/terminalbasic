/******************************************************************************
 * Разработчик: Закрытое акционерное общество "Научно исследовательский
 * институт "Центрпрограммсистем", г. Тверь (ЗАО НИИ ЦПС)
 *
 * Интеллектуальная собственность ЗАО НИИ ЦПС
 *****************************************************************************/

/**
 * @file	ringbuffer.hpp
 * @author	starling13
 * @brief	________________
 * @date	1 ноября 2016 г., 13:55
 */

#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include "cps.hpp"

template <typename T, unsigned size>
class RingQueue
{
	CPS_NOTCOPYABLE(RingQueue)
public:
	RingQueue() :
	_last(0), _length(0)
	{
	}
	~RingQueue() = default;
	
	void insert(T element)
	{
		_data[_last] = element;
		_last = (_last+1)%size;
		if (_length < size)
			++_length;
	}
	
	unsigned length() const { return _length; }
	
	unsigned last() const { return _last; }
	
	unsigned first() const
	{
		unsigned result;
		
		if (_last >= _length)
			result = _last-_length;
		else
			result = size - _length + _last;
		
		return result;
	}
	
	T *data() { return _data; }
private:
	
	unsigned _last, _length;
	T _data[size];
};

#endif

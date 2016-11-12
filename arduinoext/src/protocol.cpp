#include "protocol.hpp"

#include <assert.h>

Protocol::Message::Message(Header *head, Type type) :
_header(head)
{
	header().type = type;
}

uint16_t Protocol::Message::length() const
{
	uint16_t result = sizeof (Header);

	return (result);
}

Protocol::SessionMessage::SessionMessage(Header *head) :
Message(head, SESSION)
{
}

uint16_t Protocol::SessionMessage::length() const
{
	return (sizeof (Header));
}

Protocol::ChannelsMessage::ChannelsMessage(Header *head) :
Message(head, CHANNELS)
{
}

uint16_t Protocol::ChannelsMessage::length() const
{
    return Message::length() + sizeof (Channels) +
            channels().channelsNumber * sizeof (Channel);
}

uint8_t Protocol::ChannelsMessage::channelsNumber() const
{
	return (channels().channelsNumber);
}

Protocol::Channel Protocol::ChannelsMessage::channel(uint8_t index)
{
    assert(index < channels().channelsNumber);

    return channels().channels[index];
}

const Protocol::Channels &Protocol::ChannelsMessage::channels() const
{
    return reinterpret_cast<const Channels&>(*(&header()+1));
}

Protocol::Channels &Protocol::ChannelsMessage::channels()
{
    return reinterpret_cast<Channels&>(*(&header()+1));
}

Protocol::Type Protocol::Message::type() const
{
	return (Type(header().type));
}

Protocol::MeasureTaskMessage::MeasureTaskMessage(Header *head, Type type) :
Message(head, type)
{
}

Protocol::AnalogMeasureTaskMessage::AnalogMeasureTaskMessage(Header *head) :
MeasureTaskMessage(head, ANALOG_MEASURE)
{
}

Protocol::DigitalMeasureTaskMessage::DigitalMeasureTaskMessage(Header *head) :
MeasureTaskMessage(head, DIGITAL_MEASURE)
{
}

uint32_t Protocol::MeasureTaskMessage::period() const
{
	return (data().task.period);
}

uint16_t Protocol::MeasureTaskMessage::samplesNumber() const
{
	return (data().task.samplesNumber);
}

Protocol::MeasureMode Protocol::MeasureTaskMessage::mode() const
{
	return (Protocol::MeasureMode(data().task.mode));
}

uint8_t Protocol::MeasureTaskMessage::channelNumber() const
{
	return (data().task.channelNumber);
}

void Protocol::MeasureTaskMessage::setPeriod(uint32_t newVal)
{
	data().task.period = newVal;
}

void Protocol::MeasureTaskMessage::setSamplesNumber(uint16_t newVal)
{
	data().task.samplesNumber = newVal;
}

void Protocol::MeasureTaskMessage::setMode(MeasureMode newVal)
{
	data().task.mode = uint8_t(newVal);
}

void Protocol::MeasureTaskMessage::setChannelNumber(uint8_t newVal)
{
	data().task.channelNumber = newVal;
}

void Protocol::AnalogMeasureTaskMessage::setThreshold(uint16_t newVal)
{
	data().task.threshold = newVal;
}

Protocol::MeasureMessage::MeasureMessage(Header *head, Type typ) :
Message(head, typ)
{
}

Protocol::AnalogMeasureMessage::AnalogMeasureMessage(Header *head) :
MeasureMessage(head, ANALOG_MEASURE)
{
}

Protocol::DigitalMeasureMessage::DigitalMeasureMessage(Header *head) :
MeasureMessage(head, DIGITAL_MEASURE)
{
}

uint16_t Protocol::MeasureMessage::numberOfSamples() const
{
	return (measure().samplesNumber);
}

uint32_t Protocol::MeasureMessage::period() const
{
	return (measure().period);
}

void Protocol::MeasureMessage::setPeriod(uint32_t newVal)
{
	measure().period = newVal;
}

uint16_t Protocol::AnalogMeasureMessage::doubleSample(uint16_t index) const
{
	assert(index < measure().samplesNumber);

	if (index >= measure().samplesNumber)
		index = measure().samplesNumber;

	return (measure().data.doublePrec[index]);
}

uint8_t Protocol::DigitalMeasureMessage::sample(uint16_t index) const
{
	assert(index < measure().samplesNumber);

	if (index >= measure().samplesNumber)
		index = measure().samplesNumber;

	return (measure().data.singlePrec[index]);
}

Protocol::DeviceMessage::DeviceMessage(Protocol::Header *head) :
Message(head, DEVICE)
{
}

uint16_t Protocol::DeviceMessage::length() const
{
	return (sizeof (Header) + sizeof (Device));
}

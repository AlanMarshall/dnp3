#ifndef __CONVERSIONS_H_
#define __CONVERSIONS_H_

#include <string>

#include <openpal/gen/LogLevel.h>

#include <opendnp3/gen/ChannelState.h>
#include <opendnp3/gen/StackState.h>

#include <opendnp3/DataTypes.h>
#include <opendnp3/CommandResponse.h>
#include <opendnp3/SlaveStackConfig.h>
#include <opendnp3/MasterStackConfig.h>
#include <opendnp3/ControlRelayOutputBlock.h>
#include <opendnp3/AnalogOutput.h>
#include <opendnp3/OctetString.h>

#include <asiopal/SerialTypes.h>

using namespace DNP3::Interface;

namespace DNP3
{
namespace Adapter
{

private class Conversions
{
public:

	static System::Exception ^ convertException(const openpal::Exception& ex);

	static openpal::TimeDuration convertTimeSpan(System::TimeSpan ts);

	// Convert a .NET string to a C++ string
	static std::string convertString(System::String ^ s);
	static System::String ^ convertString(const std::string& s);

	// Convert the log filter enumeration
	static openpal::LogLevel convertLogLevel(DNP3::Interface::LogLevel level);
	static DNP3::Interface::LogLevel convertLogLevel(openpal::LogLevel level);
	
	// Converting channel state enumeration
	static ChannelState convertChannelState(opendnp3::ChannelState aState);

	// Converting stack state enumeration
	static StackState convertStackState(opendnp3::StackState aState);

	// Convert the command status enumeration
	static CommandStatus convertCommandStatus(opendnp3::CommandStatus status);
	static opendnp3::CommandStatus convertCommandStatus(CommandStatus status);

	static CommandResult convertCommandResult(opendnp3::CommandResult result);

	static CommandResponse convertCommandResponse(opendnp3::CommandResponse response);

	//functions for converting binary outputs

	static ControlCode convertControlCode(opendnp3::ControlCode code);
	static opendnp3::ControlCode Conversions::convertControlCode(ControlCode code);


	static ControlRelayOutputBlock ^ convertCommand(const opendnp3::ControlRelayOutputBlock& bo);
	static opendnp3::ControlRelayOutputBlock convertCommand(ControlRelayOutputBlock ^ bo);

	//functions for converting setpoints

	static opendnp3::AnalogOutputInt32 convertCommand(AnalogOutputInt32 ^ sp);
	static AnalogOutputInt32 ^ convertCommand(const opendnp3::AnalogOutputInt32& sp);

	static opendnp3::AnalogOutputInt16 convertCommand(AnalogOutputInt16 ^ sp);
	static AnalogOutputInt16 ^ convertCommand(const opendnp3::AnalogOutputInt16& sp);

	static opendnp3::AnalogOutputFloat32 convertCommand(AnalogOutputFloat32 ^ sp);
	static AnalogOutputFloat32 ^ convertCommand(const opendnp3::AnalogOutputFloat32& sp);

	static opendnp3::AnalogOutputDouble64 convertCommand(AnalogOutputDouble64 ^ sp);
	static AnalogOutputDouble64 ^ convertCommand(const opendnp3::AnalogOutputDouble64& sp);

	//functions for converting Measurement types
	static Binary ^ convertMeas(opendnp3::Binary meas);
	static Analog ^ convertMeas(opendnp3::Analog meas);
	static Counter ^ convertMeas(opendnp3::Counter meas);
	static SetpointStatus ^ convertMeas(opendnp3::SetpointStatus meas);
	static ControlStatus ^ convertMeas(opendnp3::ControlStatus meas);
	static OctetString^ Conversions::convertMeas(const opendnp3::OctetString& arMeas);


	static opendnp3::Binary convertMeas(Binary ^ meas);
	static opendnp3::Analog convertMeas(Analog ^ meas);
	static opendnp3::Counter convertMeas(Counter ^ meas);
	static opendnp3::SetpointStatus convertMeas(SetpointStatus ^ meas);
	static opendnp3::ControlStatus convertMeas(ControlStatus ^ meas);

	//Convert the configuration types
	static asiopal::SerialSettings convertSerialSettings(SerialSettings ^ settings);
	static opendnp3::ClassMask convertClassMask(ClassMask ^ cm);
	static opendnp3::EventMaxConfig convertEventMaxConfig(EventMaxConfig ^ cm);

	static opendnp3::StaticBinaryResponse convert(StaticBinaryResponse rsp);
	static opendnp3::StaticAnalogResponse convert(StaticAnalogResponse rsp);
	static opendnp3::StaticCounterResponse convert(StaticCounterResponse rsp);
	static opendnp3::StaticSetpointStatusResponse convert(StaticSetpointStatusResponse rsp);

	static opendnp3::EventBinaryResponse convert(EventBinaryResponse rsp);
	static opendnp3::EventAnalogResponse convert(EventAnalogResponse rsp);
	static opendnp3::EventCounterResponse convert(EventCounterResponse rsp);
	
	static opendnp3::EventPointRecord convertRecord(EventPointRecord ^ epr);
	static opendnp3::DeadbandPointRecord<double> convertRecord(DeadbandEventPointRecord<double> ^ epr);
	static opendnp3::DeadbandPointRecord<uint32_t> convertRecord(DeadbandEventPointRecord<System::UInt32> ^ epr);

	static opendnp3::LinkConfig convertConfig(LinkConfig ^ config);
	static opendnp3::AppConfig convertConfig(AppConfig ^ config);
	static opendnp3::MasterConfig convertConfig(MasterConfig ^ config);
	static opendnp3::SlaveConfig convertConfig(SlaveConfig ^ config);
	static opendnp3::DatabaseConfiguration convertConfig(DeviceTemplate ^ config);
	static opendnp3::MasterStackConfig convertConfig(MasterStackConfig ^ config);
	static opendnp3::SlaveStackConfig convertConfig(SlaveStackConfig ^ config);
};

}
}

#endif

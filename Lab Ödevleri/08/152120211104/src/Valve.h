#pragma once

#include "Device.h"

class Valve :public Device {
	bool status;

public:
	void set_valve_status(bool);
	bool get_valve_statement();
};
#include "mobile_sensors.h"
#include "core/input/input.h"

void MobileSensors::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_accelerometer"), &MobileSensors::get_accelerometer);
    ClassDB::bind_method(D_METHOD("get_gyroscope"), &MobileSensors::get_gyroscope);
}

Vector3 MobileSensors::get_accelerometer() {
    return Input::get_singleton()->get_accelerometer();
}

Vector3 MobileSensors::get_gyroscope() {
    return Input::get_singleton()->get_gyroscope();
}

MobileSensors::MobileSensors() {}

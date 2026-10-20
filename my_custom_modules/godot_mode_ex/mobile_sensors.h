#ifndef MOBILE_SENSORS_H
#define MOBILE_SENSORS_H
#include "core/object/ref_counted.h"
#include "core/variant/variant.h"

class MobileSensors : public RefCounted {
    GDCLASS(MobileSensors, RefCounted);
protected:
    static void _bind_methods();
public:
    Vector3 get_accelerometer();
    Vector3 get_gyroscope();
    MobileSensors();
};
#endif

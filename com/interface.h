#ifndef INTERFACE_H
#define INTERFACE_H
#include <libusb-1.0/libusb.h>
int open_device(libusb_device_handle **dev_handle, libusb_context *ctx);
#endif // !INTERFACE

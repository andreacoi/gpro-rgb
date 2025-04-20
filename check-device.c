#include "check-device.h"
#include <libusb-1.0/libusb.h>
#include <stdio.h>
#include <sys/types.h>

int check_device() {
  const uint16_t L_VENDOR_ID = 0x174f;  // Example vendor ID
  const uint16_t L_PRODUCT_ID = 0x1176; // Example vendor ID

  // initialize context for libusb
  libusb_context *ctx = NULL;
  // create a list of devices - iterable
  libusb_device **list = NULL;
  // initialize the context for libusb
  int r = libusb_init(&ctx);
  // get the list of devices
  ssize_t count_usb_devices = libusb_get_device_list(ctx, &list);
  // iterate over the list of devices
  for (ssize_t i = 0; i < count_usb_devices; i++) {
    // initialize a struct lib device descriptor
    struct libusb_device_descriptor desc;
    // get the device libusb_device_descriptor - a struct that contains all the
    // information about the device
    int r = libusb_get_device_descriptor(list[i], &desc);
    if (desc.idVendor == L_VENDOR_ID && desc.idProduct == L_PRODUCT_ID) {
      // free the list of devices
      libusb_free_device_list(list, 1);
      // exit the context for libusb
      libusb_exit(ctx);
      return 1;
    } else {
      continue;
    }
  }
  return 0;
}

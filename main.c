#include "check-device.h"
#include <stdio.h>

int main() {
  if (check_device() == 1) {
    printf("Device found!\n");
    return 0;
  } else {
    return -1;
  };
}

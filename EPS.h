#include <glib.h>
#include <glib/gprintf.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

class EPS {
  EPS(){};
  unsigned char EPS_cmd(uint8_t, uint8_t, uint8_t);  //command, data[0], data[1]
  ~EPS(){};
};

unsigned char EPS_cmd(uint8_t cmd, uint8_t data0, uint8_t data1)
{
  int EPS_addr = 0x23; //0x2B; factory-set address
  uint8_t packet[3];
  int file;
  I2C i2c;
  
  file = i2c.open(EPS_addr);
  
  packet[0] = cmd;
  packet[1] = data0;
  packet[2] = data1;
  
  EPS_data = i2c.write(file, packet);  //address of EPS should be a global variable in fact all of the I2C 
                      //addresses should be global or at least known by the I2C class  
}

class I2C {
  I2C(){};
  void open(int);
  void read();
  void write();
  ~I2C(){};
};

void I2C::open(int addr)
{
  int file;
  int adapter_nr = 1; /* our OBC should only have one I2C adapter */
  char filename[20];
  
  snprintf(filename, 19, "/dev/i2c-%d", adapter_nr);
  file = open(filename, O_RDWR);
  if (file < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    exit(1);
  }

/*When you have opened the device, you must specify with what device
address you want to communicate:*/

  if (ioctl(file, I2C_SLAVE, addr) < 0) {
    /* ERROR HANDLING; you can check errno to see what went wrong */
    exit(1);
  }
  return file;
}

void I2C::write (int file, uint8_t packet[], unsigned int length)
{
    if (write(file,packet,length) != length) 
    {
      /* ERROR HANDLING: i2c transaction failed */
      printf("Failed to write to the i2c bus.\n");
      buffer = g_strerror(errno);
      printf(buffer);
      printf("\n\n");
    }
}


void I2C::read (int file, uint8_t packet[], unsigned int length)
{
// Using I2C Read
        if (read(file,packet,length) != length) {
            /*ERROR HANDLING: i2c transaction failed */
            printf("Failed to read from the i2c bus.\n");
            buffer = g_strerror(errno);
            printf(buffer);
            printf("\n\n");
        }
}

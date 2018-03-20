<<<<<<< HEAD
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
#include <cstdint>
#include <iostream>
#include "command_lib.h"
#include "EPS.cpp"


int main()
{
	// snip
	/* std::string userInput = "B_STATUS";
		std::cout << "Please input a desired command." << std::endl;
		std::getline(std::cin, userInput);
		std::cout << userInput << std::endl;
	// 	end of trash */
	EPS eps;
	//std:: string commandString = "EPSComm::" + userInput; //string of EPS::+userInput 
	//need to convert commandString to unsigned int
	uint8_t command = static_cast<uint8_t>(EPSComm::GET_LASTERR); 
    eps.cmd(command,0x2222,0x03);  
	
}

=======
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <cstdint>
#include "command_lib.h"
#include "EPS.h"
using namespace std;

void eps(uint8_t cmd, uint8_t data0, uint8_t data1)
{
    uint8_t packet[] = {};
    
    packet[0] = cmd;
    packet[1] = data0;
    packet[2] = data1;
    
	length = 3;
	if (write(file_i2c, buffer, length) != length)
	{
		/*ERROR HANDLING: i2c transaction failed */
		printf("Failed to write to the i2c bus.\n");
	}
    printf("%02X%02X%02X", packet[0], packet[1], packet[2]);
}

int EPSmain()
{
    uint8_t cmd, data0, data1;
	
	
	
    cmd = static_cast<uint8_t>(EPSComm::GET_VERSION);
	//C -- cmd = (uint8_t)EPSComm::B_STATUS;
	data0 = 0x00;
	data1 = 0x01;
    
    eps(cmd, data0, data1);
}

/*class i2cReadWrite
{
	public:
	int file_i2c;
	unsigned char buffer[60];
	int length = 3;
	
	 void setup(char * id){//"/dev/i2c-1"
          char *filename = id;
          if ((file_i2c = open(filename, O_RDWR)) < 0) {
                  printf("Failed to open the i2c bus");
                  return;
          }

          int addr = 0x5a;
          if (ioctl(file_i2c, I2C_SLAVE, addr) < 0) {
                  printf("Failed to acquire bus access and/or talk to slave.\n");
                  return;
          }
        }

        string readi2cData(){
                string res;
                if (read(file_i2c, buffer, length) != length) {
                        printf("Failed to read from the i2c bus.\n");
                }
                else {
                        printf("Data read: %s\n", buffer);
                }
                return res;
        }
        void writeBytes(){
          buffer[0] = cmd;
          buffer[1] = data0;
		  buffer[2] = data1;
          if (write(file_i2c, buffer, length) != length) {
                  printf("Failed to write to the i2c bus.\n");
          }
        }
};*/

>>>>>>> 0d4940ba3a51a9c29ccd7436d59b881cce84dfd0

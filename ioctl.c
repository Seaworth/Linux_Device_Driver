#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define DEVICE_FILE "/dev/globalmem"

#define MEM_CLEAR 0x1
#define MEM_SET   0xffaa0001
#define MEM_GET   0xffaa0002

int main() {
	int fd;
	int value;

	fd = open(DEVICE_FILE, O_RDWR);
	if (fd < 0) {
		perror("Cannot open device");
		return -1;
	}

	printf("step1: ioctl mem_clear\n");
	ioctl(fd, MEM_CLEAR, &value);

	ioctl(fd, MEM_GET, &value);
	printf("step2: ioctl mem_get value=%d\n", value);

	value = 2;
	printf("step3: ioctl mem_set value=%d\n", value);
	ioctl(fd, MEM_SET, &value);

	ioctl(fd, MEM_GET, &value);
	printf("step4: ioctl mem_get value=%d\n", value);

	close(fd);
	return 0;
}


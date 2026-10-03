
#ifdef _arch_dreamcast

// SPDX-License-Identifier: GPL-2.0-only
/*
 * SD cards handling code
 *
 * Copyright (C) 2024 Paul Cercueil <paul@crapouillou.net>
 */
#include <kos.h>
#include <zlib.h>
#include <dc/sd.h>
#include <fat/fs_fat.h>
#include <stdint.h>
#include <stdio.h>

static kos_blockdev_t rv;//

void sdcard_init(void)
{
	uint8_t type;
	int err;

	if (sd_init())
		return;

	err = sd_blockdev_for_partition(0, &rv, &type);
	if (err)
		return;

	printf("Found SDCARD partition 0\n");

	err = fs_fat_init();
	if (err)
		return;

	err = fs_fat_mount("/sd", &rv, FS_FAT_MOUNT_READWRITE);
	if (err)
		return;

	printf("Mounted SDCARD partition 0 to /sd\n");
}

void sdcard_shutdown(void)
{
	fs_fat_unmount("/sd");
	fs_fat_shutdown();
	sd_shutdown();
}

int DC_SaveToSD(char* name) {

	uint8* data;
	int descriptor;
	FILE* file;
	FILE* cretfile;
	long sizef = 904;
	struct stat* statics;

	descriptor = open(name, O_RDONLY);

	if (descriptor != -1)
	{
		file = fdopen(descriptor, "rb");
		if (file)
			printf("file %s open!!!\n", name);
	}
	else
	{
		printf("file not open!!!\n");
	}

	fstat(descriptor, statics);
	printf("320 filesize %d\n", statics->st_size);
	if (statics->st_size <= 0) return -1;

	data = (uint8*)malloc(statics->st_size);


		//printf("%s", data);
	

	fread(data, 1, statics->st_size, file);
	fclose(file);
	close(descriptor);

	if (!(cretfile = fopen("/sd/duke.sav", "wb"))) {
		printf("Could not create file:\n");
		return -1;
	}
	
	if (fwrite(data, statics->st_size, 1, cretfile) < 0) {
		printf("Failed to write to file: \n");
	}
	else {
		printf("Wrote to file ok \n");
	}
	fclose(cretfile);
	free(data);

	return 0;
}

#endif
#include <stdlib.h>

#include "arduino_logger.hpp"

#include "SPI.h"
#include "SD.h"

Sd2Card card;
SdVolume volume;

static File root;

void
setup()
{
	Serial.begin(57600);
	Serial.setTimeout(3000);
	if (SD.begin(SS))
		Serial.println("SD initialized!");
	else {
		Serial.println("SD initialization error!");
		delay(2);
		abort();
	}
	root = SD.open("/", FILE_WRITE);
	if (!root) {
		Serial.println("Cant open root object!");
		delay(2);
		abort();
	}
	
	if (!root.isDirectory()) {
		Serial.println("Root is not a directory!");
		delay(2);
		abort();
	}
}

static void printDirs(File &f)
{
	f.rewindDirectory();
	Serial.println("Files list:");
	for (File ff = f.openNextFile(); ff; ff = f.openNextFile()) {
		Serial.print(ff.name());
		Serial.write('\t');
		Serial.println(ff.size());
		ff.close();
	}
}

void
loop()
{
	char c;
	char buf[32];
	while (Serial.available() <= 0);
	
	c = Serial.read();
	switch (c) {
	case 'n': {
		Serial.print("new file name:");
		int s = Serial.readBytesUntil('\r', buf, 16);
		buf[s] = 0;
		Serial.println();
		if (SD.exists(buf)) {
			Serial.print("file ");
			Serial.print(buf);
			Serial.println(" exists");
		} else {
			File f = SD.open(buf, FILE_WRITE);
			if (!f)
				Serial.println("error!");
			else {
				Serial.println("created!");
				f.println(millis());
				f.close();
			}
		}
	}
		break;
	case 'd':
		if (root)
		printDirs(root);
		break;
	case 'f':
		root.rewindDirectory();
		for (File ff = root.openNextFile(); ff; ff = root.openNextFile()) {
			if (!SD.remove(ff.name()))
				Serial.println("Can't remove file");
		}
		break;
	case 'a': {
		int s;
		Serial.println("Text to add:");
		s = Serial.readBytesUntil('\r', buf, 16);
		buf[s] = 0;
		root.rewindDirectory();
		File f = root.openNextFile(FILE_WRITE);
		if (f) {
			f.seek(f.size());
			f.print(buf);
			f.seek(0);
			s = f.readBytes(buf, 32);
			buf[s] = 0;
			Serial.println(buf);
			f.close();
		}
	}
		break;
	}
}

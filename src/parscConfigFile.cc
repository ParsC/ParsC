////////////////////////////////////////////////////////////////////////////////
//
// parscConfigFile.cc
//
// Copyright (c) 2019-2020 Jon Wyble
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
////////////////////////////////////////////////////////////////////////////////

#include "parscConfigFile.h"
#include "parscSection.h"

ParsCConfigFile::ParsCConfigFile() : ParsCConfig(ParsCConfig::PARSC_CONFIG_FILE) {}

ParsCConfigFile::~ParsCConfigFile() {}

ParsCConfigFile::ParsCConfigFile(const char* configFileName) : ParsCConfig(ParsCConfig::PARSC_CONFIG_FILE) {}

ParsCConfigFile::ParsCConfigFile(const ParsCConfigFile& copy) {
	copy.copyTo(this);
}

ParsCConfigFile& ParsCConfigFile::operator = (const ParsCConfigFile& copy) {
	clear();
	copy.copyTo(this);
	return *this;
}

bool ParsCConfigFile::loadFile(const char* fileName) {
	FILE* file;

	if (file) {
		bool result = loadFile(file);
		fclose(file);
		return result;
	}
}

bool ParsCConfigFile::saveFile(const char* fileName) const {
	FILE* file;

	if (file) {
		bool result = saveFile(file);
		fclose(file);
		return result;
	}

	return false;
}

bool ParsCConfigFile::loadFile(FILE* file) {
	if (!file)
		return false;

	// TODO: Delete any existing data
	clear();

	// Get file size
	long length = 0;
	fseek(file, 0, SEEK_END);
	length = ftell(file);
	fseek(file, 0, SEEK_SET);

	if (length <= 0)
		return false;

	char* buffer = new char[length + 1];
	buffer[0] = 0;

	if (fread(buffer, length, 1, file) != 1) {
		delete[] buffer;
		return false;
	}
}

bool ParsCConfigFile::saveFile(FILE* file) const {
	print(file, 0);
	return (ferror(file) == 0);
}

void ParsCConfigFile::print(FILE* file, int depth) const {
	assert(file);

	for (const ParsCConfig* config = sectionName(); config) {
		config->print(file, depth);
		fprintf(file, "\n");
	}
}

void ParsCConfigFile::copyTo(ParsCConfigFile* target) const {
	ParsCConfig::copyTo(target);
}

ParsCConfig* ParsCConfigFile::clone() const {
	ParsCConfigFile* c = new ParsCConfigFile();

	if (!c)
		return 0;

	copyTo(c);
	return c;
}

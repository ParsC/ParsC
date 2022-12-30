////////////////////////////////////////////////////////////////////////////////
//
// parscConfigFile.h
//
// Copyright (c) 2019-2022 Jon Wyble
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

#ifndef PARSCCONFIGFILE_H
#define PARSCCONFIGFILE_H

#include <string>
#include <vector>
#include <map>
#include "ParsC.h"

/**
 * ParsCConfigFile
 *
 * Indicates any current INI configuration file. This is what binds everything together
 * to create a so called INI file. It can be saved and loaded.
 */
class ParsCConfigFile : public ParsCConfig {
public:
	// Create an empty INI file with no name
	ParsCConfigFile();
	virtual ~ParsCConfigFile();
	// Create an INI file with a name
	ParsCConfigFile(const char* configFileName);
	ParsCConfigFile(const ParsCConfigFile& copy);
	bool loadFile(const char* fileName);
	bool saveFile(const char* fileName) const;
	bool loadFile(FILE* file);
	bool saveFile(FILE* file) const;
	void print() const {
		print(stdout, 0);
	}
	virtual void print(FILE* file, int depth = 0) const;
private:
	void copyTo(ParsCConfigFile* target) const;
protected:
	virtual ParsCConfig* clone() const;
};
#endif

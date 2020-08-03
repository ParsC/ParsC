////////////////////////////////////////////////////////////////////////////////
//
// parscSection.h
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

#ifndef PARSCSECTION_H
#define PARSCSECTION_H

#include "ParsC.h"

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

#ifndef INCLUDE_VECTOR
#include <vector>
#define INCLUDE_VECTOR
#endif

#ifndef INCLUDE_MAP
#include <map>
#define INCLUDE_MAP
#endif

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

/*
  ParsCSection

  Parses certain sections included in any current INI configuration file. Sections are
  elements for INI files that appear in brackets. They indicate what a certain block
  of keys/properties are for.
*/
class ParsCSection : public ParsCConfig {
	friend class ParsCKeyValue;
public:
	// Construct a section
	ParsCSection(const char* value);
	virtual ~ParsCSection();
	ParsCSection(const ParsCSection&);
	ParsCSection& operator=(const ParsCSection& base);
	const char* name(const char* n) const;
	const char* name(const char* n, int* i) const;
	const char* name(const char* n, double* d) const;
	const char* getText() const;
	virtual ParsCConfig* clone() const;
	virtual const char* parse(const char* p, ParsCData* data);
	virtual void print(FILE* file, int depth) const {
		print(file, depth, 0);
	}
	void print(FILE* file, int depth, std::string* str) const;
protected:
	void clearThis();
	void copyTo(ParsCSection* target) const;
	const char* readValue(const char* in, ParsCData* previousData);
};

/*
  ParsCSectionComment

  Indicates a comment in the INI file, either within any section in the current file,
  or anywhere else in the file.
*/
class ParsCSectionComment : public ParsCConfig {
public:
	// Construct an empty comment
	ParsCSectionComment();
	// Construct a comment from text
	ParsCSectionComment(const char* value);
	ParsCSectionComment(const ParsCSectionComment&);
	ParsCSectionComment& operator=(const ParsCSectionComment& base);
	virtual ~ParsCSectionComment();
	virtual ParsCConfig* clone() const;
	virtual void print(FILE* file, int depth = 0) const;
protected:
	void copyTo(ParsCSectionComment* target) const;
};
#endif
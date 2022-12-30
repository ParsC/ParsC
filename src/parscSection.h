////////////////////////////////////////////////////////////////////////////////
//
// parscSection.h
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

#ifndef PARSCSECTION_H
#define PARSCSECTION_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "ParsC.h"

/**
 * ParsCSection
 *
 * Parses certain sections included in any current INI configuration file. Sections are
 * elements for INI files that appear in brackets. They indicate what a certain block
 * of keys/properties are for.
 */
class ParsCSection : public ParsCConfig {
	friend class ParsCKeyValue;
public:
	// Construct a section
	ParsCSection(const char* sectionName);
	virtual ~ParsCSection();
	void setSectionName(const char* sectionName) {
		_sectionName = sectionName;
	}
	const char* getSectionName() const {
		return _sectionName;
	}
	virtual ParsCConfig* clone() const;
protected:
	void clearThis();
	void copyTo(ParsCSection* target) const;
	const char* _sectionName;
};

/**
 * ParsCSectionComment
 *
 * Indicates a comment within any section in the current INI file.
 */
class ParsCSectionComment : public ParsCConfig {
public:
	// Construct an empty comment
	ParsCSectionComment(const char* sectionComment);
	virtual ~ParsCSectionComment();
	void setSectionComment(const char* sectionComment);
	const char* getSectionComment();
	virtual void print(FILE* file, int depth) const {
		print(file, depth = 0);
	}
	void print(FILE* file, int depth) const;
	virtual ParsCConfig* clone() const;
protected:
	void copyTo(ParsCSectionComment* target) const;
	const char* _sectionComment;
};
#endif

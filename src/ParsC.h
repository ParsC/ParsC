////////////////////////////////////////////////////////////////////////////////
//
// ParsC.h
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

#ifndef PARSC_H
#define PARSC_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <ctype.h>
#include <iostream>
#include "parscParser.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4530)
#pragma warning(disable : 4786)
#endif

class ParsCConfigFile;
class ParsCSection;
class ParsCKeyValue;
class ParsCSectionComment;
class ParsCData;

/*
  ParsCBase

  The supreme base for every class included in the ParsC INI configuration file parser.
  Also binds with the ParsCConfig class.
*/
class ParsCBase {
	friend class ParsCConfig;
	friend class ParsCConfigFile;
	friend class ParsCSection;
public:
	ParsCBase() : _userData(0) {}
	virtual ~ParsCBase() {}
	virtual void print(FILE* file, int depth) const = 0;
	static void setCondensedWhiteSpace(bool condense) {
		_condensedWhiteSpace = condense;
	}
	static bool isCondensedWhiteSpace() {
		return _condensedWhiteSpace;
	}
	void setUserData(void* user) {
		_userData = user;
	}
	void* getUserData() {
		return _userData;
	}
	const void* getUserData() const {
		return _userData;
	}
	virtual const char* parse(const char* p, ParsCData* data) = 0;
private:
	struct Entity {
		const char* string;
		unsigned int stringLength;
		char c;
	};

	enum {
		ENTITY_NUMBER = 5,
		MAXIMUM_ENTITY_LENGTH = 6
	};

	ParsCBase(const ParsCBase&);
	void operator=(const ParsCBase& base);
	static Entity entity[ENTITY_NUMBER];
	static bool _condensedWhiteSpace;
protected:
	static const char* skipWhiteSpace(const char*);
	inline static bool isWhiteSpace(char ch) {
		return (isspace((unsigned char)ch) || ch == '\n' || ch == '\r');
	}
	inline static bool isWhiteSpace(int ch) {
		if (ch < 256)
			return isWhiteSpace((char)ch);

		return false;
	}
	static const char* getEntity(const char* in, char* value, int* length);
	void* _userData;
};

/*
  ParsCConfig

  The parent class for most functions in ParsC. This is what holds all of the elements
  included in INI configuration files in general.
*/
class ParsCConfig : public ParsCBase {
	friend class ParsCConfigFile;
	friend class ParsCSection;
	friend class ParsCKeyValue;
public:
	enum ConfigType {
		PARSC_CONFIG_FILE,
		PARSC_SECTION,
		PARSC_KEY,
		PARSC_VALUE,
		PARSC_SECTION_COMMENT
	};

	ParsCConfig();
	~ParsCConfig();
	void clear();
	void setValue(std::string value) {
		_value = value;
	}
	std::string getValue() const {
		return _value;
	}
	ParsCConfig* parent() {
		return _parent;
	}
	const ParsCConfig* parent() const {
		return _parent;
	}
	ParsCConfig* sectionName() {
		return _sectionName;
	}
	const ParsCConfig* sectionName() const {
		return _sectionName;
	}
	const ParsCConfig* sectionName(const char* value) const;
	ParsCConfig* sectionName(const char* value) {
		return const_cast<ParsCConfig*>((const_cast<const ParsCConfig*>(this))->sectionName(value));
	}
private:
	ParsCConfig(const ParsCConfig&);
	void operator=(const ParsCConfig& base);
protected:
	ParsCConfig(ConfigType type);
	void copyTo(ParsCConfig* target) const;
	std::string _value;
	ParsCConfig* _parent;
	ConfigType _type;
	ParsCConfig* _sectionName;
	ParsCConfig* _previous;
	ParsCConfig* _next;
};
#endif

////////////////////////////////////////////////////////////////////////////////
//
// ParsC.h
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

/**
 * ParsCConfig
 *
 * The parent class for most functions in ParsC. This is what holds all of the elements
 * included in INI configuration files in general.
 */
class ParsCConfig {
	friend class ParsCConfigFile;
	friend class ParsCKeyValue;
	friend class ParsCSection;
public:
	enum ConfigType {
		PARSC_CONFIG_FILE,
		PARSC_NAME,
		PARSC_VALUE,
		PARSC_SECTION,
		PARSC_SECTION_COMMENT
	};

	ParsCConfig(ConfigType type);
	virtual ~ParsCConfig();
	void clear();
	void setValue(const char* value) {
		_value = value;
	}
	const char* getValue() const {
		return _value;
	}
	void setUserData(void* userData) {
		_userData = userData;
	}
	void* getUserData() const {
		return _userData;
	}
	const char* keyValue() const {
		return _value.c_str();
	}
	const ParsCConfig* keyName(const char* value) const;
	const char* sectionValue() const {
		return _section.c_str();
	}
	const ParsCConfig* sectionName(const char* value) const;
	ParsCConfig* sectionName() {
		return _sectionName;
	}
private:
	ParsCConfig(const ParsCConfig&);
	void operator=(const ParsCConfig& base);
protected:
	void copyTo(ParsCConfig* target) const;
	const char* _value;
	const char* _section;
	ConfigType* _type;
	ParsCConfig* _keyName;
	ParsCConfig* _sectionName;
	ParsCConfig* _previous;
	ParsCConfig* _next;
	void* _userData;
	bool _condensedWhiteSpace;
};
#endif

////////////////////////////////////////////////////////////////////////////////
//
// parscKeyValue.h
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

#ifndef PARSCKEYVALUE_H
#define PARSCKEYVALUE_H

#include <string>
#include <iostream>
#include "ParsC.h"

/**
 * ParsCKeyValue
 *
 * Indicates both names and values within any current INI configuration file, included
 * in what is called a key or property. A name is a character which appears before the
 * equals sign (delimiter), and the value follows. You can add quotation marks to any
 * value if need be.
 *
 * Examples: Name=Value or Name="Value"
 */
class ParsCKeyValue : public ParsCConfig {
	friend class ParsCSection;
public:
	// Construct a name or value
	ParsCKeyValue(const char* name, const char* value);
	virtual ~ParsCKeyValue();
	ParsCKeyValue* setName(const char* name) {
		_name = name;
	}
	const char* getName() const {
		return _name.c_str();
	}
	ParsCKeyValue* setValue(const char* value) const {
		_value = value;
	}
	const char* getValue() const {
		return _value.c_str();
	}
	virtual void print(FILE* file, int depth) const {
		print(file, depth, 0);
	}
	void print(FILE* file, int depth, std::string* str) const;
	virtual ParsCConfig* clone() const;
private:
	std::string _name;
	std::string _value;
	ParsCKeyValue* _previous;
	ParsCKeyValue* _next;
protected:
	void clearThis();
	void copyTo(ParsCSection* target) const;
};
#endif

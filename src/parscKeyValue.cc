////////////////////////////////////////////////////////////////////////////////
//
// parscKeyValue.cc
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

#include <cstdio>
#include "ParsCKeyValue.h"

ParsCKeyValue::ParsCKeyValue(const char* name, const char* value) {
	if (name) {
		ParsCConfig(ParsCConfig::PARSC_NAME);
	}

	if (value) {
		ParsCConfig(ParsCConfig::PARSC_VALUE);
	}

	_name = name;
	_value = value;
	_configFile = 0;
	_previous = _next = 0;
}

ParsCKeyValue::~ParsCKeyValue() {
	clearThis();
}

ParsCKeyValue& ParsCKeyValue::operator=(const ParsCKeyValue& base) {
	clearThis();
	base.copyTo(this);
	return *this;
}

void ParsCKeyValue::print(FILE* file, int depth, std::string str) const {
	std::string name, value;

	if (_value.find('\"') == std::string::npos) {
		if (file) {
			fprintf(file, "%s=\"%s\"", name.c_str(), value.c_str());
		}

		if (str) {
			(*str) += name;
			(*str) += "=\"";
			(*str) += value;
			(*str) += "\""
		}
	}
}

ParsCConfig* ParsCKeyValue::clone() const {
	ParsCKeyValue* c = new ParsCKeyValue();

	if (!c)
		return 0;

	copyTo(c);
	return c;
}

void ParsCKeyValue::clearThis() {
	clear();
}

void ParsCKeyValue::copyTo(ParsCSection* target) const {
	ParsCConfig::copyTo(target);
}

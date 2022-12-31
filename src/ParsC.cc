////////////////////////////////////////////////////////////////////////////////
//
// ParsC.cc
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

#include "ParsC.h"

bool ParsCConfig::_condensedWhiteSpace = true;

ParsCConfig::ParsCConfig(ConfigType type) {
	_type = type;
	_sectionName = 0;
	_previous = 0;
	_next = 0;
}

ParsCConfig::~ParsCConfig() {
	ParsCConfig* config = _sectionName;
	ParsCConfig* temp = 0;

	while (config) {
		temp = config;
		config = config->_next;
		delete temp;
	}
}

void ParsCConfig::clear() {
	ParsCConfig* config = _sectionName;
	ParsCConfig* temp = 0;

	while (config) {
		temp = config;
		config = config->_next;
		delete temp;
	}

	_sectionName = 0;
}

const ParsCConfig* ParsCConfig::keyName(const char* value) const {
	const ParsCConfig* name;

	for (name = _keyName; name; name = name->_next) {
		if (strcmp(name->keyValue(), value) == 0)
			return name;
	}

	return name;
}

const ParsCConfig* ParsCConfig::sectionName(const char* name) const {
	const ParsCConfig* section;

	for (section = _sectionName; section; section = section->_next) {
		if (strcmp(section->sectionValue(), name) == 0)
			return section;
	}

	return section;
}

void ParsCConfig::copyTo(ParsCConfig* target) const {
	target->setValue(_value.c_str());
	target->_userData = _userData;
}

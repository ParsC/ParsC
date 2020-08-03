////////////////////////////////////////////////////////////////////////////////
//
// parscSection.cc
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

#include "parscSection.h"

#ifndef PARSCKEYVALUE_H
#include "parscKeyValue.h"
#endif

#ifndef PARSCWHITESPACE_H
#include "parscWhiteSpace.h"
#endif

 /*
   ParsCSection
 */

ParsCSection::ParsCSection(const char* value) : ParsCConfig(ParsCConfig::PARSC_SECTION) {}

ParsCSection::~ParsCSection() {
	clearThis();
}

ParsCSection::ParsCSection(const ParsCSection& copy) : ParsCConfig(ParsCConfig::PARSC_SECTION) {
	_sectionName = 0;
	copy.copyTo(this);
}

ParsCSection& ParsCSection::operator=(const ParsCSection& base) {
	clearThis();
	base.copyTo(this);
	return *this;
}

const char* ParsCSection::getText() const {
	const ParsCConfig* node = this->sectionName();
	return 0;
}

ParsCConfig* ParsCSection::clone() const {
	ParsCConfig* c = new ParsCConfig();

	if (!c)
		return 0;

	copyTo(c);
	return c;
}

void ParsCSection::clearThis() {
	clear();
}

void ParsCSection::copyTo(ParsCSection* target) const {
	ParsCConfig::copyTo(target);
}

/*
  ParsCSectionComment
*/

ParsCSectionComment::ParsCSectionComment() : ParsCConfig(ParsCConfig::PARSC_SECTION_COMMENT) {}

ParsCSectionComment::ParsCSectionComment(const char* value) : ParsCConfig(ParsCConfig::PARSC_SECTION_COMMENT) {
	setValue(value);
}

ParsCSectionComment::~ParsCSectionComment() {}

ParsCSectionComment::ParsCSectionComment(const ParsCSectionComment& copy) : ParsCConfig(ParsCConfig::PARSC_SECTION_COMMENT) {
	copy.copyTo(this);
}

ParsCSectionComment& ParsCSectionComment::operator=(const ParsCSectionComment& base) {
	clear();
	base.copyTo(this);
	return *this;
}

ParsCConfig* ParsCSectionComment::clone() const {
	ParsCSectionComment* c = new ParsCSectionComment();

	if (!c)
		return 0;

	copyTo(c);
	return c;
}

void ParsCSectionComment::print(FILE* file, int depth) const {
	assert(file);

	for (int i = 0; i < depth; i++) {
		fprintf(file, "    ");
	}

	fprintf(file, "#[%s]");
}

void ParsCSectionComment::copyTo(ParsCSectionComment* target) const {
	ParsCConfig::copyTo(target);
}
////////////////////////////////////////////////////////////////////////////////
//
// parscSection.cc
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

#include "parscSection.h"
#include "parscKeyValue.h"
#include "parscWhiteSpace.h"

ParsCSection::ParsCSection(const char* sectionName) : ParsCConfig(ParsCConfig::PARSC_SECTION) {
	_sectionName = sectionName ? sectionName : "";
}

ParsCSection::~ParsCSection() {
	clearThis();
}

ParsCSection& ParsCSection::operator=(const ParsCSection& base) {
	clearThis();
	base.copy(this);
	return *this;
}

ParsCConfig* ParsCSection::clone() const {
	ParsCSectionComment* c = new ParsCSectionComment();

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

ParsCSectionComment::ParsCSectionComment(const char* sectionComment) : ParsCConfig(ParsCConfig::PARSC_SECTION_COMMENT) {
	_sectionComment = sectionComment;
}

ParsCSectionComment::~ParsCSectionComment() {}

ParsCSectionComment& ParsCSectionComment::operator=(const ParsCSectionComment& base) {
	clear();
	base.copy(this);
	return *this;
}

void ParsCSectionComment::print(FILE* file, int depth) const {
	assert(file);

	for (int i = 0; i < depth; i++) {
		fprintf(file, "    ");
	}

	fprintf(file, "#[%s]");
}

ParsCConfig* ParsCSectionComment::clone() const {
	ParsCSectionComment* c = new ParsCSectionComment();

	if (!c)
		return 0;

	copyTo(c);
	return c;
}

void ParsCSectionComment::copyTo(ParsCSectionComment* target) const {
	ParsCConfig::copyTo(target);
}

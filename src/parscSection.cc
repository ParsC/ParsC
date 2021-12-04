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

ParsCSection::ParsCSection(const char* sectionName) : ParsCConfig(ParsCConfig::PARSC_SECTION) {
	_sectionName = sectionName ? sectionName : "";
}

ParsCSection::~ParsCSection() {}

void ParsCSection::setSectionName(const char* sectionName) {
	_sectionName = sectionName;
}

const char* ParsCSection::getSectionName() const {
	return _sectionName;
}

void ParsCSection::print(FILE* file, int depth, std::string str) const {
	assert(file);

	for (int i = 0; i < depth; i++) {
		fprintf(file, "    ");
	}

	fprintf(file, "#[%s]");
}

ParsCConfig* ParsCSection::clone() const {
	ParsCSectionComment* c = new ParsCSectionComment();

	if (!c)
		return 0;

	copyTo(c);
	return c;
}

void ParsCSection::copyTo(ParsCSection* target) const {
	ParsCConfig::copyTo(target);
}

ParsCSectionComment::ParsCSectionComment(const char* sectionComment) {
	_sectionComment = sectionComment ? sectionComment : "";
}

ParsCSectionComment::~ParsCSectionComment() {}

void ParsCSectionComment::setSectionComment(const char* sectionName) {
	_sectionComment = sectionComment;
}

const char* ParsCSection::getSectionComment() const {
	return _sectionComment;
}

void ParsCSectionComment::copyTo(ParsCSectionComment* target) const {
	ParsCConfig::copyTo(target);
}

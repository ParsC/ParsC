////////////////////////////////////////////////////////////////////////////////
//
// parscParser.cc
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

#include "parsCParser.h"

ParsCParser::ParsCParser() {
	_commentCharacter = "#";
	_delimiter = "=";
	_error = "";
	_errorCode = "";
}

ParsCParser::~ParsCParser() {}

void ParsCParser::setCommentCharacter(char c) {
	_commentCharacter = c;
}

void ParsCParser::setDelimiter(char d) {
	_delimiter = d;
}

const char* ParsCParser::getError() const {
	return _error.c_str();
}

const char* ParsCParser::getErrorCode() const {
	return _errorCode.c_str();
}

void ParsCParser::setError(const char* code, const char* message) {
	_errorCode = code ? code : "";
	_error = message ? message : "";
}

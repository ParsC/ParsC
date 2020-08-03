////////////////////////////////////////////////////////////////////////////////
//
// parscParser.h
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

#ifndef PARSCPARSER_H
#define PARSCPARSER_H

#ifndef INCLUDE_STRING
#include <string>
#define INCLUDE_STRING
#endif

#ifndef INCLUDE_IOSTREAM
#include <iostream>
#define INCLUDE_IOSTREAM
#endif

/*
  ParsCParser

  The secondary class for most functions in the ParsC INI configuration file parser.
*/
class ParsCParser {
	std::string _error;
	std::string _errorCode;
public:
	// Construct an INI parser
	ParsCParser();
	virtual ~ParsCParser();
	void setCommentCharacter(char c);
	void setDelimiter(char c);
	const char* getError() const;
	const char* getErrorCode() const;
protected:
	void setError(const char* code, const char* message);
	char _commentCharacter;
	char _delimiter;
};
#endif
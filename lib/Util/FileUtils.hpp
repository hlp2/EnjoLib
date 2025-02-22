/*
Modified BSD License

This file originates from:
http://sf.net/projects/enjomitchsorbit

Copyright (c) 2012, Szymon "Enjo" Ender
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef FILE_UTILS_HPP_INCLUDED
#define FILE_UTILS_HPP_INCLUDED

#include <Util/VecStr.hpp>

class istream;

namespace EnjoLib
{
class FileUtils
{
public:
    stdfwd::vector<VecStr > GetConfigSections( const EnjoLib::Str & fileName,
            const EnjoLib::Str & startMarker,
            const EnjoLib::Str & endMarker ) const;
    bool FileExists( const EnjoLib::Str & fileName ) const;
    bool DirExists( const EnjoLib::Str & dirName ) const;
    void CreateDirIfNotExistsLinux(const EnjoLib::Str & dirName) const;
    EnjoLib::Str GetBaseDir(const EnjoLib::Str & fullPath) const;
    size_t GetNumLinesFile( const EnjoLib::Str & fileName, bool skipHeader = false ) const;
    size_t GetNumLinesFile( std::istream & is, bool skipHeader = false ) const;
    void Remove(const EnjoLib::Str & fileName);

private:
    VecStr GetOneSection( std::istream & file, const EnjoLib::Str & endMarker ) const;
};
}

#endif

/*
Modified BSD License

This file is a part of Statistical package and originates from:
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

#ifndef EIGENABSTRACT_H
#define EIGENABSTRACT_H

#include <3rdParty/stdfwd.hh>
#include "EigenValueVector.hpp"
#include "../Template/CorradePointerFwd.h"
namespace EnjoLib
{
class Matrix;

class EigenAbstract
{
    public:
        EigenAbstract();
        virtual ~EigenAbstract();

        Matrix GetSortedFeatureVectorNumber( const Matrix & m, unsigned number) const;
        Matrix GetSortedFeatureVectorFactor( const Matrix & m, double leaveFactor ) const;
        Matrix GetSortedFeatureVector( const Matrix & m ) const;
        stdfwd::vector<EigenValueVector> GetEigenValVec( const Matrix & m, bool sorted ) const;

        static Corrade::Containers::Pointer<EigenAbstract> CreateEigen3();
        static Corrade::Containers::Pointer<EigenAbstract> CreateMKL();
        static Corrade::Containers::Pointer<EigenAbstract> CreateDefault();
#ifdef USE_LIB_NEWMAT
        static Corrade::Containers::Pointer<EigenAbstract> CreateNewmat();
#endif
        static Corrade::Containers::Pointer<EigenAbstract> CreateNumpy();

    protected:
        virtual stdfwd::vector<EigenValueVector> GetEigenValVecClient( const Matrix & m ) const = 0;

    private:

};
}
#endif // EIGENABSTRACT_H

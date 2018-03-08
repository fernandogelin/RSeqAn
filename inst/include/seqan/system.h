// ==========================================================================
//                 SeqAn - The Library for Sequence Analysis
// ==========================================================================
// Copyright (c) 2006-2018, Knut Reinert, FU Berlin
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Knut Reinert or the FU Berlin nor the names of
//       its contributors may be used to endorse or promote products derived
//       from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL KNUT REINERT OR THE FU BERLIN BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
// OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
// DAMAGE.
//
// ==========================================================================

#ifndef SEQAN_HEADER_SYSTEM_H
#define SEQAN_HEADER_SYSTEM_H

#include <seqan/file.h>

//____________________________________________________________________________
// prerequisites

#include <cstdio>
#include <ctime>
#include <string>
#include <iostream>

#if defined(STDLIB_VS) || defined(__MINGW32__)

#include <windows.h>

#else //#ifdef STDLIB_VS

#include <cstdlib>
#include <climits>
#include <errno.h>
#include <semaphore.h>
#if SEQAN_ASYNC_IO
#include <aio.h>
#endif

#ifdef __MINGW32__
#include <seqan/mman.h>
#else
#include <sys/mman.h>
#endif

#ifndef O_LARGEFILE
#define O_LARGEFILE 0
#endif

#ifndef O_DIRECT
#define O_DIRECT 0
#endif

#endif //#ifdef STDLIB_VS

#include <seqan/system/system_forwards.h>
#ifndef STDLIB_VS
#include <seqan/system/file_forwards.h>
#endif  // #ifndef STDLIB_VS

//____________________________________________________________________________
// multi-threading

#include <seqan/system/system_base.h>

//____________________________________________________________________________
// synchronous and asynchronous files

#include <seqan/system/file_sync.h>
#if SEQAN_ASYNC_IO
#include <seqan/system/system_event_win.h>
#include <seqan/system/file_async.h>
#endif
#include <seqan/system/file_directory.h>

#endif //#ifndef SEQAN_HEADER_...

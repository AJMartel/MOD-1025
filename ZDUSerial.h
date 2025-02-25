/*
Copyright (c) 2016, Embedded Adventures
All rights reserved.
Contact us at source [at] embeddedadventures.com
www.embeddedadventures.com
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice,
  this list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright
  notice, this list of conditions and the following disclaimer in the
  documentation and/or other materials provided with the distribution.
- Neither the name of Embedded Adventures nor the names of its contributors
  may be used to endorse or promote products derived from this software
  without specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF 
THE POSSIBILITY OF SUCH DAMAGE.
*/

// ZDU0110RFX Serial Wrapper Arduino library
// Written originally by Embedded Adventures

#ifndef ZDUSerial_h
#define	ZDUSerial_h

#include "Stream.h"
#include "ZDU0110RFX.h"

class ZDUSerial : public Stream {
private:
	ZDU0110RFXClass	zdu;
	int irq;
public:
	ZDUSerial();
	~ZDUSerial();
	
	void	begin(int irq, unsigned long baud);
	void	begin(int irq);
	int	available();
	int	peek();
	int	read();
	void	flush();
	
	size_t	write(uint8_t n);
	inline size_t write(unsigned long n) { return write((uint8_t)n); }
    	inline size_t write(long n) { return write((uint8_t)n); }
    	inline size_t write(unsigned int n) { return write((uint8_t)n); }
    	inline size_t write(int n) { return write((uint8_t)n); }
	
	using 	Print::write; // pull in write(str) and write(buf, size) from Print
};


#endif

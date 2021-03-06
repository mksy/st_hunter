// AFile.cpp: implementation of the AFile class.
//
//////////////////////////////////////////////////////////////////////
#include "include.h"
#include "AFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFile::AFile()
{
  this->fin=-1;
}

AFile::AFile(const char *cFileName, unsigned int iFileFlags, unsigned int iFileMode)
{
  this->fin=_open(cFileName, iFileFlags, iFileMode, &this->ferr);
}

AFile::~AFile()
{
  if(this->fin!=-1)
  {
    _close(this->fin, &this->ferr);
    this->fin=-1;
  }
}

void AFile::FClose()
{
  if(this->fin!=-1)
  {
    _close(this->fin, &this->ferr);
    this->fin=-1;
  }
}

int AFile::FOpen(const char *cFileName, unsigned int iFileFlags, unsigned int iFileMode)
{
  if(this->fin!=-1)
    FClose();
  return (this->fin=_open(cFileName, iFileFlags, iFileMode, &this->ferr));
}

int AFile::FRead(void *cBuffer, int iByteCount)
{
  if(this->fin==-1)
    return 0; //-1 ?
  return (_read(this->fin, cBuffer, iByteCount, &this->ferr));
}

int AFile::FWrite(const void *cBuffer, int iByteCount)
{
  if(this->fin==-1)
    return 0; //-1 ?
  return (_write(this->fin, cBuffer, iByteCount, &this->ferr));
}

int AFile::LSeek(unsigned int offset, unsigned int origin)
{
  if(this->fin==-1)
    return 0; //-1 ?
  return (_lseek(this->fin, offset, origin, &this->ferr, &this->ferr));
}

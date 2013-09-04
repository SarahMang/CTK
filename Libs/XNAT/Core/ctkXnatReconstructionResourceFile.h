/*=============================================================================

  Plugin: org.commontk.xnat

  Copyright (c) University College London,
    Centre for Medical Image Computing

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

=============================================================================*/

#ifndef ctkXnatReconstructionResourceFile_h
#define ctkXnatReconstructionResourceFile_h

#include "ctkXNATCoreExport.h"

#include "ctkXnatObject.h"

class ctkXnatConnection;
class ctkXnatReconstructionResourceFilePrivate;

class CTK_XNAT_CORE_EXPORT ctkXnatReconstructionResourceFile : public ctkXnatObject
{

public:

  typedef QSharedPointer<ctkXnatReconstructionResourceFile> Pointer;
  typedef QWeakPointer<ctkXnatReconstructionResourceFile> WeakPointer;
  
  static Pointer Create();
  virtual ~ctkXnatReconstructionResourceFile();
  
//  const QString& uri() const;
//  void setUri(const QString& uri);

  void download(const QString& filename);
  void upload(const QString& filename);

  void reset();
  void remove();
  
  bool isFile() const;

  /* bool receivesFiles() const; */
  /* bool holdsFiles() const; */
  /* bool isDeletable() const; */
  /* bool isModifiable() const; */
  
private:
  
  friend class qRestResult;
  explicit ctkXnatReconstructionResourceFile();
  virtual void fetchImpl();
  
  Q_DECLARE_PRIVATE(ctkXnatReconstructionResourceFile);
  Q_DISABLE_COPY(ctkXnatReconstructionResourceFile);
};

#endif
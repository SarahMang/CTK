/*=========================================================================

  Library:   CTK

  Copyright (c) Kitware Inc.

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0.txt

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.

  This file was originally developed by Jean-Christophe Fillion-Robin, Kitware Inc.
  and was partially funded by NIH grant 3P41RR013218-12S1

=========================================================================*/

#ifndef __ctkDirectoryListView_h
#define __ctkDirectoryListView_h

// Qt includes
#include <QWidget>

// QtGUI includes
#include "ctkWidgetsExport.h"

class ctkDirectoryListViewPrivate;

class CTK_WIDGETS_EXPORT ctkDirectoryListView : public QWidget
{
  Q_OBJECT
  Q_PROPERTY(QStringList directoryList READ directoryList WRITE setDirectoryList NOTIFY directoryListChanged);
public:
  /// Superclass typedef
  typedef QWidget Superclass;

  /// Constructor
  explicit ctkDirectoryListView(QWidget* parent = 0);

  /// Destructor
  virtual ~ctkDirectoryListView();

  /// Return True if the \a path has already been added
  bool hasDirectory(const QString& path)const;

  QStringList directoryList(bool absolutePath = false)const;

  QStringList selectedDirectoryList(bool absolutePath = false)const;

public slots:

  /// If \a path exists, add it to the view and emit signal directoryListChanged().
  /// \sa directoryListChanged()
  void addDirectory(const QString& path);

  /// Remove all entries and set \a paths has current list.
  /// The signal directoryListChanged() is emitted if the current list of directories is
  /// different from the provided one.
  /// \sa addDirectory(), directoryListChanged()
  void setDirectoryList(const QStringList& paths);

  /// Remove \a path from the list.
  /// The signal directoryListChanged() is emitted if the path was in the list.
  /// \sa directoryListChanged()
  void removeDirectory(const QString& path);

  /// \sa selectAllDirectories()
  void removeSelectedDirectories();

  /// Select all directories.
  void selectAllDirectories();

  /// Clear the current directory selection.
  void clearDirectorySelection();

signals:
  /// This signal is emitted when a directory is added to the view.
  void directoryListChanged();

protected:
  QScopedPointer<ctkDirectoryListViewPrivate> d_ptr;

private:
  Q_DECLARE_PRIVATE(ctkDirectoryListView);
  Q_DISABLE_COPY(ctkDirectoryListView);

};

#endif

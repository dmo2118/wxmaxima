﻿// -*- mode: c++; c-file-style: "linux"; c-basic-offset: 2; indent-tabs-mode: nil -*-
//
//  Copyright (C) 2007-2015 Andrej Vodopivec <andrej.vodopivec@gmail.com>
//            (C) 2014-2016 Gunter Königsmann <wxMaxima@physikbuch.de>
//
//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//  SPDX-License-Identifier: GPL-2.0+

#ifndef SUBSUPCELL_H
#define SUBSUPCELL_H

#include "Cell.h"

class SubSupCell : public Cell
{
public:
  SubSupCell(Cell *parent, Configuration **config, CellPointers *cellPointers);

  ~SubSupCell();

  std::list<Cell *> GetInnerCells() override;

  Cell *Copy() override;

  void SetBase(Cell *base);

  void SetIndex(Cell *index);

  void SetExponent(Cell *expt);

  void SetPreSub(Cell *expt);

  void SetPreSup(Cell *expt);

  void SetPostSub(Cell *expt){SetIndex(expt);}

  void SetPostSup(Cell *expt){SetExponent(expt);}
  
  void RecalculateHeight(int fontsize) override;

  void RecalculateWidths(int fontsize) override;

  virtual void Draw(wxPoint point) override;

  wxString ToString() override;

  wxString ToMatlab() override;

  wxString ToTeX() override;

  wxString ToXML() override;

  wxString ToOMML() override;

  wxString ToMathML() override;

protected:
  Cell *m_baseCell;
  Cell *m_postSupCell;
  Cell *m_postSubCell;
  Cell *m_preSupCell;
  Cell *m_preSubCell;
  std::list<Cell *> m_innerCellList;
};

#endif // SUBSUPCELL_H

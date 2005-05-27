/*
 * wire-item.h
 *
 *
 * Authors:
 *  Richard Hult <rhult@hem.passagen.se>
 *  Ricardo Markiewicz <rmarkie@fi.uba.ar>
 *  Andres de Barbara <adebarbara@fi.uba.ar>
 *
 * Web page: http://arrakis.lug.fi.uba.ar/
 *
 * Copyright (C) 1999-2001  Richard Hult
 * Copyright (C) 2003,2004  LUGFI
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */
#ifndef __WIRE_ITEM_H
#define __WIRE_ITEM_H

#include <config.h>
#include <gnome.h>

#include "schematic-view.h"
#include "sheet-item.h"
#include "wire.h"

#define WIRE_ITEM(obj)          (G_TYPE_CHECK_INSTANCE_CAST (obj, wire_item_get_type (), WireItem))
#define WIRE_ITEM_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST (klass, wire_item_get_type (), WireItemClass))
#define IS_WIRE_ITEM(obj)       (G_TYPE_CHECK_INSTANCE_TYPE (obj, wire_item_get_type ()))

typedef struct _WireItemPriv WireItemPriv;

typedef enum {
	WIRE_DIR_NONE = 0,
	WIRE_DIR_HORIZ = 1,
	WIRE_DIR_VERT = 2,
	WIRE_DIR_DIAG = 3
} WireDir;

typedef struct {
	SheetItem parent_object;
	WireItemPriv *priv;
} WireItem;

typedef struct {
	SheetItemClass parent_class;
} WireItemClass;

GType wire_item_get_type (void);
WireItem *wire_item_new (Sheet *sheet, Wire *wire);
void wire_item_initiate (Sheet *sheet);
void wire_item_get_start_pos (WireItem *item, SheetPos *pos);
void wire_item_get_length (WireItem *item, SheetPos *pos);

#endif

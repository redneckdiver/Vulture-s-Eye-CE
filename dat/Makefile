#
# This file is generated automatically.  Do not edit.
# Your changes will be lost.  See sys/unix/NewInstall.unx.
# Identify this file:
MAKEFILE_DAT=1

###
### Start hints/linux PRE
###
# (new segment at source line 6 )
# Linux hints file
# This hints file provides a single-user tty build for Linux, specifically
# for Ubuntu dapper.


#PREFIX=/usr
PREFIX=$(wildcard ~)/nh/install
HACKDIR=$(PREFIX)/games/lib/$(GAME)dir
SHELLDIR = $(PREFIX)/games
INSTDIR=$(HACKDIR)
VARDIR = $(HACKDIR)



POSTINSTALL=cp -n sys/unix/sysconf $(INSTDIR)/sysconf; $(CHOWN) $(GAMEUID) $(INSTDIR)/sysconf; $(CHGRP) $(GAMEGRP) $(INSTDIR)/sysconf; chmod $(VARFILEPERM) $(INSTDIR)/sysconf;

CFLAGS=-g -O -I../include -DNOTPARMDECL
CFLAGS+=-DDLB
CFLAGS+=-DCOMPRESS=\"/bin/gzip\" -DCOMPRESS_EXTENSION=\".gz\"
CFLAGS+=-DSYSCF -DSYSCF_FILE=\"$(HACKDIR)/sysconf\" -DSECURE
CFLAGS+=-DTIMED_DELAY
CFLAGS+=-DHACKDIR=\"$(HACKDIR)\"
CFLAGS+=-DDUMPLOG
CFLAGS+=-DCONFIG_ERROR_SECURE=FALSE
CFLAGS+=-DCURSES_GRAPHICS
#CFLAGS+=-DEXTRA_SANITY_CHECKS
#CFLAGS+=-DEDIT_GETLIN
#CFLAGS+=-DSCORE_ON_BOTL
#CFLAGS+=-DMSGHANDLER
#CFLAGS+=-DTTY_TILES_ESCCODES

LINK=$(CC)
# Only needed for GLIBC stack trace:
LFLAGS=-rdynamic

WINSRC = $(WINTTYSRC) $(WINCURSESSRC)
WINOBJ = $(WINTTYOBJ) $(WINCURSESOBJ)
WINLIB = $(WINTTYLIB) $(WINCURSESLIB)

# if TTY_TILES_ESCCODES
#WINSRC += tile.c
#WINOBJ += tile.o

WINTTYLIB=-lncurses -ltinfo

CHOWN=true
CHGRP=true

VARDIRPERM = 0755
VARFILEPERM = 0600
GAMEPERM = 0755
### End hints/linux PRE

###
### Start Makefile.dat
###
#      NetHack Datafiles Makefile.dat $NHDT-Date: 1447844574 2018/04/25 19:25:54 $ $NHDT-Branch: NetHack-3.6.0 $:$NHDT-Revision: 1.22 $
# Copyright (c) 2018 by Pasi Kallinen
# NetHack may be freely redistributed.  See license for details.

# Root of source tree:
NHSROOT=..

# for Atari
# SHELL=E:/GEMINI2/MUPFEL.TTP
# UUDECODE=uudecode

VARDAT = bogusmon data engrave epitaph rumors quest.dat oracles options

all:	$(VARDAT) spec_levs quest_levs dungeon

../util/makedefs:
	(cd ../util ; $(MAKE) makedefs)

../util/dgn_comp:
	(cd ../util ; $(MAKE) dgn_comp)

../util/lev_comp:
	(cd ../util ; $(MAKE) lev_comp)

../util/tile2x11:
	(cd ../util ; $(MAKE) tile2x11)

../util/tile2beos:
	(cd ../util ; $(MAKE) tile2beos)

../util/tile2bmp:
	(cd ../util ; $(MAKE) tile2bmp)

x11tiles: ../util/tile2x11 ../win/share/monsters.txt ../win/share/objects.txt \
				../win/share/other.txt \
                                ../win/share/monsters.txt
	../util/tile2x11 ../win/share/monsters.txt ../win/share/objects.txt \
				../win/share/other.txt \
                                -grayscale ../win/share/monsters.txt

beostiles: ../util/tile2beos ../win/share/monsters.txt \
				../win/share/objects.txt \
				../win/share/other.txt
	../util/tile2beos ../win/share/monsters.txt \
				../win/share/objects.txt \
				../win/share/other.txt

nhtiles.bmp: ../util/tile2bmp ../win/share/monsters.txt \
				../win/share/objects.txt \
				../win/share/other.txt
	../util/tile2bmp $@

NetHack.ad: ../win/X11/NetHack.ad
# handle "#define foo bar" -lines
	grep ^#define ../win/X11/NetHack.ad | \
		sed -e 's/^#define/s/g' -e 's/  */ /g' \
		    -e 's/$$/ g/g' > NetHack.ad.tmp
	grep -v ^#define ../win/X11/NetHack.ad | \
		sed -f NetHack.ad.tmp > NetHack.ad
	-rm -f NetHack.ad.tmp

pet_mark.xbm: ../win/X11/pet_mark.xbm
	cp ../win/X11/pet_mark.xbm pet_mark.xbm

pilemark.xbm: ../win/X11/pilemark.xbm
	cp ../win/X11/pilemark.xbm pilemark.xbm

rip.xpm: ../win/X11/rip.xpm
	cp ../win/X11/rip.xpm rip.xpm

mapbg.xpm: ../win/gnome/mapbg.xpm
	cp ../win/gnome/mapbg.xpm mapbg.xpm

nhsplash.xpm: ../win/Qt/nhsplash.xpm
	cp ../win/Qt/nhsplash.xpm nhsplash.xpm

nethack.icns: ../win/Qt/nhicns.uu
	$(UUDECODE) ../win/Qt/nhicns.uu

Info.plist: ../win/Qt/Info.pli
	cp ../win/Qt/Info.pli Info.plist

../util/tile2img.ttp:
	(cd ../util ; $(MAKE) tile2img.ttp)

../util/xpm2img.ttp:
	(cd ../util ; $(MAKE) xpm2img.ttp)
nh16.img: ../util/tile2img.ttp ../win/share/monsters.txt \
				../win/share/objects.txt ../win/share/other.txt
	../util/tile2img.ttp nh16.img

rip.img: ../util/xpm2img.ttp
	../util/xpm2img.ttp ../win/X11/rip.xpm rip.img
title.img:
	# cp ../win/gem/title.img title.img
	$(UUDECODE) ../win/gem/title.uu

GEM_RSC.RSC:
	# cp ../win/gem/GEM_RSC.RSC GEM_RSC.RSC
	$(UUDECODE) ../win/gem/gem_rsc.uu


data:	data.base ../util/makedefs
	../util/makedefs -d

rumors:	rumors.tru rumors.fal ../util/makedefs
	../util/makedefs -r

quest.dat:	quest.txt ../util/makedefs
	../util/makedefs -q

oracles:	oracles.txt ../util/makedefs
	../util/makedefs -h

engrave:	engrave.txt ../util/makedefs
	../util/makedefs -s

epitaph:	epitaph.txt ../util/makedefs
	../util/makedefs -s

bogusmon:	bogusmon.txt ../util/makedefs
	../util/makedefs -s

# note: 'options' should have already been made when include/date.h was created
options:	../util/makedefs
	../util/makedefs -v


spec_levs: ../util/lev_comp \
	bigroom.des castle.des endgame.des gehennom.des knox.des medusa.des \
	mines.des oracle.des sokoban.des tower.des yendor.des
	../util/lev_comp bigroom.des
	../util/lev_comp castle.des
	../util/lev_comp endgame.des
	../util/lev_comp gehennom.des
	../util/lev_comp knox.des
	../util/lev_comp medusa.des
	../util/lev_comp mines.des
	../util/lev_comp oracle.des
	../util/lev_comp sokoban.des
	../util/lev_comp tower.des
	../util/lev_comp yendor.des
	touch spec_levs

quest_levs: ../util/lev_comp \
	Arch.des Barb.des Caveman.des Healer.des Knight.des Monk.des \
	Priest.des Ranger.des Rogue.des Samurai.des Tourist.des Valkyrie.des \
	Wizard.des
	../util/lev_comp Arch.des
	../util/lev_comp Barb.des
	../util/lev_comp Caveman.des
	../util/lev_comp Healer.des
	../util/lev_comp Knight.des
	../util/lev_comp Monk.des
	../util/lev_comp Priest.des
	../util/lev_comp Ranger.des
	../util/lev_comp Rogue.des
	../util/lev_comp Samurai.des
	../util/lev_comp Tourist.des
	../util/lev_comp Valkyrie.des
	../util/lev_comp Wizard.des
	touch quest_levs

dungeon: dungeon.def ../util/makedefs ../util/dgn_comp
	../util/makedefs -e
	../util/dgn_comp dungeon.pdf

# gitinfo.txt is optionally made by src/Makefile when creating date.h
clean:
	-rm -f gitinfo.txt

spotless: clean
	-rm -f spec_levs quest_levs *.lev $(VARDAT) dungeon dungeon.pdf
	-rm -f nhdat x11tiles beostiles pet_mark.xbm pilemark.xbm rip.xpm mapbg.xpm
	-rm -f rip.img GEM_RSC.RSC title.img nh16.img NetHack.ad
	-rm -f nhsplash.xpm nhtiles.bmp
### End Makefile.dat

###
### Start hints/linux POST
###
### End hints/linux POST

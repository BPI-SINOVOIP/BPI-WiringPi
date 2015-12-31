#
# Makefile:
#	wiringPi - Wiring Compatable library for the Raspberry Pi
#	https://projects.drogon.net/wiring-pi
#
#	Copyright (c) 2012-2013 Gordon Henderson
#################################################################################
# This file is part of wiringPi:
#	Wiring Compatable library for the Raspberry Pi
#
#    wiringPi is free software: you can redistribute it and/or modify
#    it under the terms of the GNU Lesser General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    wiringPi is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public License
#    along with wiringPi.  If not, see <http://www.gnu.org/licenses/>.
#################################################################################


#DEBUG	= -g -O0
DEBUG	= -O3
CC	= gcc
INCLUDE	= -I/usr/local/include
CFLAGS	= $(DEBUG) -Wall $(INCLUDE) -Winline -pipe

LDFLAGS	= -L/usr/local/lib
LDLIBS    = -lwiringPi -lwiringPiDev -lpthread -lm

###############################################################################

SRC	=	52pi.c hello.c lcd1602.c test.c

OBJ	=	$(SRC:.c=.o)

BINS	=	$(SRC:.c=)

all:	$(BINS)

52pi:	52pi.o
	@echo [link]
	@$(CC) -o $@ 52pi.o $(LDFLAGS) $(LDLIBS)

hello:	hello.o
	@echo [link]
	@$(CC) -o $@ hello.o $(LDFLAGS) $(LDLIBS)

lcd1602:	lcd1602.o
	@echo [link]
	@$(CC) -o $@ lcd1602.o $(LDFLAGS) $(LDLIBS)

test:	test.o
	@echo [link]
	@$(CC) -o $@ test.o $(LDFLAGS) $(LDLIBS)

.c.o:
	@echo [CC] $<
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@echo "[Clean]"
	@rm -f $(OBJ) *~ core tags $(BINS)

tags:	$(SRC)
	@echo [ctags]
	@ctags $(SRC)

depend:
	makedepend -Y $(SRC)

# DO NOT DELETE

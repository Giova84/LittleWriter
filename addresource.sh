#!/bin/sh

rc -o Littlewriter.rsrc Littlewriter.rdef
xres -o LittleWriter Littlewriter.rsrc
mimeset -f LittleWriter

# -*- python -*-
# $Header: /nfs/slac/g/glast/ground/cvs/EventIntegrity/SConscript,v 1.4 2009/01/23 00:06:59 ecephas Exp $
# Authors: H. Kelly <heather@milkyway.gsfc.nasa.gov>
# Version: EventIntegrity-00-07-00
Import('baseEnv')
Import('listFiles')
Import('packages')
progEnv = baseEnv.Clone()
libEnv = baseEnv.Clone()

libEnv.Tool('EventIntegrityLib', depsOnly = 1)
EventIntegrity = libEnv.SharedLibrary('EventIntegrity', listFiles(['src/*.cxx','src/Dll/*.cxx']))


progEnv.Tool('EventIntegrityLib')
test_EventIntegrity = progEnv.GaudiProgram('test_EventIntegrity', listFiles(['src/test/*.cxx']), test = 1)

progEnv.Tool('registerObjects', package = 'EventIntegrity', libraries = [EventIntegrity], testApps = [test_EventIntegrity], includes = listFiles(['EventIntegrity/*.h']))




